#ifndef SHE_TEST_GTEST_FORMAT_H
#define SHE_TEST_GTEST_FORMAT_H

#include <chrono>

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

class gtest : public common::test_info<> {
 public:
  gtest(const std::vector<std::tuple<std::string, std::string>>& list) : test_info(list) {
    using namespace print_color;
    using namespace common;
    colorful("[==========] ", GREEN_COLOR);
    printf("Running %d tests from %d test suites.\n", total_number_of_tests, total_number_of_suites);
    colorful_ln("[----------] ", "Global test environment set-up.", GREEN_COLOR);
    colorful("[----------] ", GREEN_COLOR);
    printf("%d tests from %s\n\n", total_number_of_tests, module_name.c_str());
  }
  ~gtest() override {
    using namespace print_color;
    using namespace common;
    colorful_ln("\n[----------] ", "Global test environment tear-down.", GREEN_COLOR);
    colorful("[==========] ", GREEN_COLOR);
    printf("%d tests from %d test suites run. (%d ms total)\n", total_number_of_tests, total_number_of_suites,
           total_time);
    colorful("[  PASSED  ] ", GREEN_COLOR);
    printf("%d tests\n\n", total_number_of_tests - failed_tests);
    if (failed_tests) {
      // failed info
    }
  }

   void NO_TEST_SUITE(const std::string& suite_name) noexcept override{
    using namespace common;
    using namespace print_color;
    std::string msg = suite_name ;
    colorful_ln("[ RUN      ] ", msg, GREEN_COLOR);
    msg = suite_name;
    colorful_ln("NO ", msg, RED_COLOR);
    colorful_ln("[  FAILED  ] ", msg, RED_COLOR);
  }

   void NO_TEST_CASE(const std::string& suite_name, const std::string& test_name) noexcept override {
    using namespace common;
    using namespace print_color;
    std::string msg = suite_name + ", " + test_name;
    colorful_ln("[ RUN      ] ", msg, GREEN_COLOR);
    msg = test_name;
    colorful_ln("NO ", msg, RED_COLOR);
    colorful_ln("[  FAILED  ] ", msg, RED_COLOR);
  }

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const details::test_function& waiting_to_run) noexcept override {
    using namespace common;
    using namespace print_color;
    int now_failed_tests = failed_tests;
    std::string msg      = test_suite_name + ", " + test_name;
    colorful_ln("[ RUN      ] ", msg, GREEN_COLOR);

    // Record execution time
    auto using_times = run_and_check(waiting_to_run);
    total_time += using_times;

    const std::string durationString = std::to_string(using_times) + "ms";
    msg += "(" + durationString + ")";
    if (now_failed_tests != failed_tests) {
      // failed
      colorful_ln("[  FAILED  ] ", msg, RED_COLOR);
    } else {
      // success
      colorful_ln("[       OK ] ", msg, GREEN_COLOR);
    }
  }
};

}  // namespace output_format

}  // namespace she_test

#endif  // SHE_TEST_GTEST_FORMAT_H
