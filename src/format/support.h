#ifndef SHE_TEST_FORMAT_SUPPORT_H
#define SHE_TEST_FORMAT_SUPPORT_H

#include <cstdio>
#include <string>

#include "color.h"

namespace she_test::format {

static void colorful(const std::string& str1, const char* color = color::RESET_COLOR) {
  printf("%s%s%s", color, str1.c_str(), color::RESET_COLOR);
}
static void colorful(const std::string& str1, const std::string& str2, const char* color = color::RESET_COLOR) {
  printf("%s%s%s%s", color, str1.c_str(), color::RESET_COLOR, str2.c_str());
}
static void colorful_ln(const std::string& str, const char* color = color::RESET_COLOR) {
  printf("%s%s%s\n", color, str.c_str(), color::RESET_COLOR);
}
static void colorful_ln(const std::string& str, const std::string& str2, const char* color = color::RESET_COLOR) {
  printf("%s%s%s%s\n", color, str.c_str(), color::RESET_COLOR, str2.c_str());
}
}  // namespace she_test::format

#endif  // SHE_TEST_FORMAT_SUPPORT_H
