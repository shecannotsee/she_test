#ifndef SHE_TEST_S_TEST_V1_H
#define SHE_TEST_S_TEST_V1_H
#include <chrono>
#include <functional>

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

using namespace print_color;
using test_function = std::function<bool()>;

class she_test_v1 : public common::test_info<> {
 public:
  she_test_v1() : test_info() {
    using namespace common;
    colorful_ln("[she_test] ", "Framework begins testing...", PURPLE_COLOR);

    colorful_ln("[she_test] ", "...\n", PURPLE_COLOR);
  }
  ~she_test_v1() override {
    using namespace common;
    colorful_ln("\n[she_test] ", "All test cases have ended running.", PURPLE_COLOR);
    colorful("[she_test] >> ", PURPLE_COLOR);
    printf("%d tests from %d test suites ran. (%d ms total)\n", total_number_of_tests, total_number_of_suites,
           total_time);
    colorful("[she_test] >> ", PURPLE_COLOR);
    printf("PASSED %d tests\n\n", total_number_of_tests - failed_tests);
    if (failed_tests) {
      // failed info
    }
  }

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const test_function& waiting_to_run) noexcept override {
    using namespace common;
    int now_failed_tests = failed_tests;
    std::string msg      = test_suite_name + " - " + test_name;
    colorful_ln("[she_test] READY TO RACE...>> " + msg, YELLOW_COLOR);
    // Record execution time
    const auto start = std::chrono::high_resolution_clock::now();
    run_and_check(waiting_to_run);
    const auto end      = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    total_time += duration.count();
    const std::string consume_time = std::to_string(duration.count()) + " ms";
    if (now_failed_tests != failed_tests) {
      // failed
      colorful_ln("[she_test] RACE COMPLETED. >> FAILED(" + consume_time + ")", RED_COLOR);
    } else {
      // success
      colorful_ln("[she_test] RACE COMPLETED. >> SUCCESS(" + consume_time + ")", GREEN_COLOR);
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

#endif  // SHE_TEST_S_TEST_V1_H
