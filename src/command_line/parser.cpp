#include "parser.h"

#include <sstream>

auto she_test::command_line::parse(const int argc, char** argv) -> std::vector<details::parameter_pack> {
  std::vector<details::parameter_pack> ops;
  std::vector<std::string> args;

  if (argv != nullptr) {
    args = std::move(std::vector<std::string>(argv, argv + argc));
  }

  // There are no additional parameters
  if (args.size() <= 1) {
    ops.emplace_back();
    ops.back().key = details::options::RUN_ALL_TESTS;
    return ops;
  }

  enum class state {
    COMMAND,
    PARAMETER,  // command param
    ERROR,
  };

  auto current_state = state::ERROR;
  for (const auto& arg : args) {
    if (const auto it = details::options_table.find(arg); it != details::options_table.end()) {
      // found command
      ops.emplace_back();
      ops.back().key = it->second;
      current_state  = state::COMMAND;
      continue;
    }

    if (current_state == state::COMMAND) {
      // The command is followed by parameters by default.
      ops.back().value.emplace_back(arg);  // Add params
    } else {
      // error command
      details::parameter_pack error_temp;
      error_temp.key = details::options::UNKNOWN;
      error_temp.value.emplace_back(arg);
      ops.emplace_back(error_temp);
    }
  }
  return ops;
}

auto she_test::command_line::split_test_case_name(const std::string& input) -> std::vector<std::string> {
  if (input.empty()) {
    throw std::invalid_argument("Input string is empty");
  }
  if (input.find('.') == std::string::npos) {
    return {input};
  }

  std::vector<std::string> result;
  std::string temp;
  std::istringstream stream(input);

  while (std::getline(stream, temp, '.')) {
    if (temp.empty()) {
      throw std::invalid_argument("Input string contains consecutive or trailing '.'");
    }
    result.push_back(temp);
  }

  return result;
}