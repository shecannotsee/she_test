#ifndef SHE_TEST_S_TEST_V1_H
#define SHE_TEST_S_TEST_V1_H

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

using namespace print_color;

class she_test_v1 : public common::test_info<> {
 public:
  explicit she_test_v1(const std::vector<std::tuple<std::string, std::string>>& list) : test_info(list) {
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

  void NO_TEST_SUITE(const std::string& suite_name) noexcept override {
    using namespace common;
    using namespace print_color;
    std::string msg = suite_name;
    colorful_ln("[she_test] READY TO RACE...>>", msg, YELLOW_COLOR);
    msg = suite_name;
    colorful_ln("NO ", msg, RED_COLOR);
    colorful_ln("[she_test] FAILED. >>", msg, RED_COLOR);
  }

  void NO_TEST_CASE(const std::string& suite_name, const std::string& test_name) noexcept override {
    using namespace common;
    using namespace print_color;
    std::string msg = suite_name + ", " + test_name;
    colorful_ln("[she_test] READY TO RACE...>> ", msg, YELLOW_COLOR);
    msg = test_name;
    colorful_ln("NO ", msg, RED_COLOR);
    colorful_ln("[she_test] FAILED. >>", msg, RED_COLOR);
  }

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const details::test_function& waiting_to_run) noexcept override {
    using namespace common;
    int now_failed_tests = failed_tests;
    std::string msg      = test_suite_name + " - " + test_name;
    colorful_ln("[she_test] READY TO RACE...>> " + msg, YELLOW_COLOR);
    // Record execution time
    auto using_times = run_and_check(waiting_to_run);
    total_time += using_times;
    const std::string consume_time = std::to_string(using_times) + " ms";
    if (now_failed_tests != failed_tests) {
      // failed
      colorful_ln("[she_test] RACE COMPLETED. >> FAILED(" + consume_time + ")", RED_COLOR);
    } else {
      // success
      colorful_ln("[she_test] RACE COMPLETED. >> SUCCESS(" + consume_time + ")", GREEN_COLOR);
    }
  }
};

}  // namespace output_format

}  // namespace she_test

#endif  // SHE_TEST_S_TEST_V1_H
