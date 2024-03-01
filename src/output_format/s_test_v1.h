//
// Created by shecannotsee on 24-2-29.
//

#ifndef S_TEST_V1_H
#define S_TEST_V1_H
#include <chrono>
#include <functional>

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

using namespace print_color;
using test_function = std::function<bool()>;

class s_test_v1 : public common::test_info<> {
 public:
  s_test_v1() : test_info() {
  }
  ~s_test_v1() override {

  }

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const test_function& waiting_to_run) noexcept override {
    using namespace common;
    int now_failed_tests = failed_tests;
    std::string msg      = test_suite_name + " - " + test_name;
    colorful_ln("[READY TO RACE... ] >>>  " + msg, YELLOW_COLOR);
    // Record execution time
    const auto start = std::chrono::high_resolution_clock::now();
    run_and_check(waiting_to_run);
    const auto end                 = std::chrono::high_resolution_clock::now();
    const auto duration            = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    const std::string consume_time = std::to_string(duration.count()) + "ms";
    if (now_failed_tests != failed_tests) {
      // failed
      colorful_ln("[Running done,look] >>> FAILED  >>> ", consume_time, RED_COLOR);
    } else {
      // success
      colorful_ln("[Running done,look] >>> SUCCESS >>> ", consume_time, GREEN_COLOR);
    }
  }

 private:
  void run_and_check(const test_function& waiting_to_run) override {
    if (waiting_to_run) {
      if (!waiting_to_run()) {
        failed_tests++;
      }
    } else {
      common::colorful_ln("no function to run", RED_COLOR);
    }
  }
};

}  // namespace output_format

}  // namespace she_test

#endif  // S_TEST_V1_H
