#ifndef SHE_TEST_FORMAT_COLOR_H
#define SHE_TEST_FORMAT_COLOR_H

#include <string>

namespace she_test::color {

constexpr const char* RESET_COLOR  = "[0m";
constexpr const char* RED_COLOR    = "[31m";
constexpr const char* GREEN_COLOR  = "[32m";
constexpr const char* YELLOW_COLOR = "[33m";
constexpr const char* PURPLE_COLOR = "[35m";
constexpr const char* BLUE_COLOR   = "[34m";
const std::string RESET_COLOR_S    = "[0m";
const std::string RED_COLOR_S      = "[31m";
const std::string GREEN_COLOR_S    = "[32m";
const std::string YELLOW_COLOR_S   = "[33m";
const std::string PURPLE_COLOR_S   = "[35m";
const std::string BLUE_COLOR_S     = "[34m";

}  // namespace she_test::color

#endif  // SHE_TEST_FORMAT_COLOR_H
