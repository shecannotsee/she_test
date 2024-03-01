//
// Created by shecannotsee on 24-2-29.
//

#ifndef OUTPUT_FORMAT_COMMON_H
#define OUTPUT_FORMAT_COMMON_H

#include <stdio.h>

#include "../print_color.h"

namespace she_test {

namespace output_format {

namespace common {

template <typename integer_type = int>
struct test_info {
  static_assert(std::is_integral<integer_type>::value, "integer_type must be an integral type");

  integer_type total_number_of_tests{1};
  integer_type failed_tests{0};
  integer_type total_number_of_suites{1};
  std::string module_name{"gtest_module"};

  virtual void READY_TO_RACE(const std::string&, const std::string&, const details::test_function&) noexcept = 0;

 private:
  virtual void run_and_check(const details::test_function&) = 0;
};

using namespace print_color;

static void colorful(const std::string& str1, const char* color = RESET_COLOR) {
  printf("%s%s%s", color, str1.c_str(), RESET_COLOR);
}
static void colorful(const std::string& str1, const std::string& str2, const char* color = RESET_COLOR) {
  printf("%s%s%s%s", color, str1.c_str(), RESET_COLOR, str2.c_str());
}

static void colorful_ln(const std::string& str, const char* color = RESET_COLOR) {
  printf("%s%s%s\n", color, str.c_str(), RESET_COLOR);
}

static void colorful_ln(const std::string& str, const std::string& str2, const char* color = RESET_COLOR) {
  printf("%s%s%s%s\n", color, str.c_str(), RESET_COLOR, str2.c_str());
}

}  // namespace common

}  // namespace output_format

}  // namespace she_test

#endif  // OUTPUT_FORMAT_COMMON_H
