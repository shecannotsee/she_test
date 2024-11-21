#ifndef SHE_TEST_COMMAND_LINE_PARSER_H
#define SHE_TEST_COMMAND_LINE_PARSER_H

#include <vector>

#include "options.h"

namespace she_test::details {
struct parameter_pack {
  options key{};
  std::vector<std::string> value{};
};
}  // namespace she_test::details

namespace she_test::command_line {

// Convert the parameter to a state
auto parse(int argc, char** argv) -> std::vector<details::parameter_pack>;

// Check the validity of the test name
auto split_test_case_name(const std::string& input) -> std::vector<std::string>;

};  // namespace she_test::command_line

#endif  // SHE_TEST_COMMAND_LINE_PARSER_H
