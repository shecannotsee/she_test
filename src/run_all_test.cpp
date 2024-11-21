#include "run_all_test.h"

#include <she_test.h>

#include <iostream>

#include "command_line/options.h"
#include "command_line/parser.h"
#include "test_case_registry/multi_level_test_case.h"

namespace she_test::details {

void exec_version() {
  std::cout << "she_test version " << version << std::endl;
}

void exec_help() {
  std::cout << help_message << std::endl;
}

void exec_list_all_tests() {
  for (const auto& multi_level_name : multi_level_test_case::get_test_case_list()) {
    for (int i = 0; i < multi_level_name.size(); i++) {
      std::cout << multi_level_name[i];
      if (i != multi_level_name.size() - 1) {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}

void exec_run_some_tests(std::vector<std::vector<std::string>>& use, const std::vector<std::string>& op_value) {
  for (const auto& test_case_string : op_value) {
    if (const auto test_case = command_line::split_test_case_name(test_case_string);
        multi_level_test_case::test_case_exists(test_case)) {
      use.emplace_back(test_case);
    }
  }
}

void exec_exclude_some_tests(std::vector<std::vector<std::string>>& use, const std::vector<std::string>& op_value) {
}

void exec_run_all_tests(const std::vector<std::vector<std::string>>& all, std::vector<std::vector<std::string>>& use) {
  use = all;
}

void exec_unknown(const parameter_pack& op) {
  std::cout << "error options:\n";
  for (const auto& error_options : op.value) {
    std::cout << error_options << std::endl;
  }
}

}  // namespace she_test::details
