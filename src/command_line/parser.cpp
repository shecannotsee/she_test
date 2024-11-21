#include "parser.h"

she_test::parser& she_test::parser::get_instance() {
  static parser instance;
  return instance;
}
void she_test::parser::parse(int argc, char** argv) {
  std::vector<std::string> args;

  if (argv != nullptr) {
    args = std::move(std::vector<std::string>(argv, argv + argc));
  }

  if (args.size() <= 1) {
    // There are no additional parameters
    ops_.emplace_back();
    ops_.back().key = details::options::RUN_ALL_TESTS;
    return;
  }

  enum class state {
    COMMAND,
    PARAMETER,  // command param
    ERROR,
  };

  auto current_state = state::ERROR;
  for (int i = 1; i < args.size(); ++i) {
    auto it = details::options_table.find(args[i]);
    if (it != details::options_table.end()) {
      // found command
      ops_.emplace_back();
      ops_.back().key = it->second;
      current_state   = state::COMMAND;
      continue;
    }

    if (current_state == state::COMMAND) {
      // add param
      ops_.back().value.emplace_back(args[i]);
    } else {
      // error command
      details::parameter_pack error_temp;
      error_temp.key = details::options::UNKNOWN;
      error_temp.value.emplace_back(args[i]);
      ops_.emplace_back(error_temp);
    }
  }
}

std::vector<she_test::details::parameter_pack> she_test::parser::get_ops() {
  auto ret = std::move(ops_);
  ops_.clear();
  return ret;
}

auto she_test::parser::split_suite_name_and_test_case(const std::string& input)
    -> std::tuple<std::string, std::string> {
  size_t pos = input.find('.');
  if (pos != std::string::npos) {
    std::string first  = input.substr(0, pos);
    std::string second = input.substr(pos + 1);
    return std::make_tuple(first, second);
  }
  const std::string error_message = "error param:" + input;
  throw std::runtime_error(error_message);
}