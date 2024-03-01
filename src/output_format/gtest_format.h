//
// Created by shecannotsee on 24-2-29.
//

#ifndef GTEST_FORMAT_H
#define GTEST_FORMAT_H

#include <chrono>
#include <iostream>

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

using namespace print_color;

class gtest : public common::test_info<> {
 public:
  gtest() : test_info() {
    using namespace common;
    colorful("[==========] ", GREEN_COLOR);
    printf("Running %d tests from %d test suites.\n", total_number_of_tests, total_number_of_suites);
    colorful_ln("[----------] ", "Global test environment set-up.", GREEN_COLOR);
    colorful("[----------] ", GREEN_COLOR);
    printf("%d tests from %s\n\n", total_number_of_tests, module_name.c_str());
  }
  ~gtest() {
    using namespace common;
    colorful_ln("\n[----------] ", "Global test environment tear-down.", GREEN_COLOR);
    colorful("[==========] ", GREEN_COLOR);
    printf("%d tests from %d test suites ran. (0 ms total)\n", total_number_of_tests, total_number_of_suites);
    colorful("[  PASSED  ] ", GREEN_COLOR);
    printf("%d tests", total_number_of_tests - failed_tests);
    if (failed_tests) {
      // failed info
    }
  }

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const details::test_function& waiting_to_run) noexcept override {
    using namespace common;
    int now_failed_tests = failed_tests;
    std::string msg      = test_suite_name + ", " + test_name;
    colorful_ln("[ RUN      ] ", msg, GREEN_COLOR);
    // Record execution time
    const auto start = std::chrono::high_resolution_clock::now();
    run_and_check(waiting_to_run);
    const auto end             = std::chrono::high_resolution_clock::now();
    std::string durationString = std::to_string(((end - start)).count()) + "ms";
    msg += "(" + durationString + ")";
    if (now_failed_tests != failed_tests) {
      // failed
      colorful_ln("[  FAILED  ] ", msg, RED_COLOR);
    } else {
      // success
      colorful_ln("[       OK ] ", msg, GREEN_COLOR);
    }
  }

 private:
  void run_and_check(const details::test_function& waiting_to_run) override {
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

#endif  // GTEST_FORMAT_H
