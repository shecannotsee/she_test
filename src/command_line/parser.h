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

class parser {
 public:
  static parser& get_instance();

 private:
  parser() = default;

  std::vector<details::parameter_pack> ops_{};

 public:
  // Convert the parameter to a state
  void parse(int argc, char** argv);

  // Use after parsing(this->parse)
  auto get_ops() -> std::vector<details::parameter_pack>;

  // Check the validity of the test name
  static auto split_suite_name_and_test_case(const std::string& input) -> std::tuple<std::string, std::string>;
};

}  // namespace she_test

#endif  // SHE_TEST_COMMAND_LINE_PARSER_H
