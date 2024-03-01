#ifndef PRINT_COLOR_H
#define PRINT_COLOR_H

#include <string>

namespace she_test {
namespace print_color {
static const char* RESET_COLOR   = "[0m";
static const char* RED_COLOR     = "[31m";
static const char* GREEN_COLOR   = "[32m";
static const char* YELLOW_COLOR  = "[33m";
static const char* PURPLE_COLOR  = "[35m";
static const char* BLUE_COLOR    = "[34m";
const std::string RESET_COLOR_S  = "[0m";
const std::string RED_COLOR_S    = "[31m";
const std::string GREEN_COLOR_S  = "[32m";
const std::string YELLOW_COLOR_S = "[33m";
const std::string PURPLE_COLOR_S = "[35m";
const std::string BLUE_COLOR_S   = "[34m";
}  // namespace print_color
}  // namespace she_test

#endif  // PRINT_COLOR_H
