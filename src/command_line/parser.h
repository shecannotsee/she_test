#ifndef SHE_TEST_COMMAND_LINE_PARSER_H
#define SHE_TEST_COMMAND_LINE_PARSER_H

#include <functional>
#include <stdexcept>
#include <vector>

#include "options.h"

namespace she_test {

namespace details {
struct parameter_pack {
  options key{};
  std::vector<std::string> value{};
};
}  // namespace details

namespace command_line {
// Convert the parameter to a state
auto parse(int argc, char** argv) -> std::vector<details::parameter_pack>;

// Check the validity of the test name
auto split_test_case_name(const std::string& input) -> std::vector<std::string>;
};  // namespace command_line

}  // namespace she_test

#endif  // SHE_TEST_COMMAND_LINE_PARSER_H
