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
using namespace print_color;

static void printf_green(std::string str) {
  printf("%s%s%s", GREEN_COLOR.c_str(), str.c_str(), RESET_COLOR.c_str());
}
static void println_green(std::string str) {
  printf("%s%s%s\n", GREEN_COLOR.c_str(), str.c_str(), RESET_COLOR.c_str());
}

}  // namespace common

}  // namespace output_format

}  // namespace she_test

#endif  // OUTPUT_FORMAT_COMMON_H
