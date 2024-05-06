//
// Created by shecannotsee on 24-4-26.
//

#include "command_line.h"

#include <iostream>
#include <string>

namespace she_test {
void command_line::parse(int argc, char** argv) {
  const std::vector<std::string> args(argv, argv + argc);

  if (args.size() <= 1) {
    // There are no additional parameters
    ops_.emplace_back();
    ops_.back().key = options::RUN_ALL_TESTS;
    return;
  }

  enum class state {
    COMMAND,
    PARAMETER,  // command param
    ERROR,
  };

  auto current_state = state::ERROR;
  for (int i = 1; i < args.size(); ++i) {
    auto it = options_table.find(args[i]);
    if (it != options_table.end()) {
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
      details::parame_packages error_temp;
      error_temp.key = options::UNKNOW;
      error_temp.value.emplace_back(args[i]);
      ops_.emplace_back(error_temp);
    }
  }
}

}  // namespace she_test
