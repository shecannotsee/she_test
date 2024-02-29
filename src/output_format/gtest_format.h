//
// Created by shecannotsee on 24-2-29.
//

#ifndef GTEST_FORMAT_H
#define GTEST_FORMAT_H

#include <iostream>

#include "../print_color.h"
#include "common.h"

namespace she_test {

namespace output_format {

using namespace print_color;

class gtest {
 private:
  bool pass{false};
  int total_number_of_tests_{1};
  int failed_test_{0};
  int total_number_of_suites_{1};
  std::string module_name{"gtest_module"};

 public:
  gtest() {
    using namespace common;
    printf_green("[==========] ");
    printf("Running %d tests from %d test suites.\n", total_number_of_tests_, total_number_of_suites_);
    printf_green("[----------] ");
    printf("Global test environment set-up.\n");
    printf_green("[----------] ");
    printf("%d tests from %s\n\n", total_number_of_tests_, module_name.c_str());
  }
  ~gtest() {
    using namespace common;
    printf_green("\n[----------] ");
    printf("Global test environment tear-down\n");
    printf_green("[----------] ");
    printf("Global test environment tear-down\n");
    printf_green("[==========] ");
    printf("%d tests from %d test suites ran. (0 ms total)\n", total_number_of_tests_, total_number_of_suites_);
    printf_green("[  PASSED  ] ");
    printf("%d tests", total_number_of_tests_ - failed_test_);
    if (!pass) {
      // failed info
    }
  }
};

}  // namespace output_format

}  // namespace she_test

#endif  // GTEST_FORMAT_H
