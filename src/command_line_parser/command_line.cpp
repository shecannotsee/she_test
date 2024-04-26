//
// Created by shecannotsee on 24-4-26.
//

#include "command_line.h"

#include <iostream>
#include <string>

namespace she_test {
void command_line::parse(int argc, char** argv) {
  const std::vector<std::string> args(argv, argv + argc);

  enum class state : uint8_t {
    COMMAND,
    UKNOWN,
  };

  if (args.size() > 1) {
    auto current_state = state::UKNOWN;
    for (int i = 1; i < args.size(); ++i) {
      auto it = options_table.find(args[i]);
      if (it != options_table.end()) {
        ops_.emplace_back();
        ops_.back().key = it->second;
        current_state   = state::COMMAND;
      } else {
        // no key
        if (current_state == state::COMMAND) {
          // TODO:Add param
          ops_.back().value.emplace_back(args[i]);
        } else {
          // TODO:error param
          error_param_.emplace_back(args[i]);
        }
      }
    }
  } else {
    ops_.emplace_back();
    ops_.back().key = options::RUN_ALL_TESTS;
  }

  exec();
}

void command_line::exec() {
  std::cout << "common param:\n";
  for (const auto& group : ops_) {
    if (0) {
      //
    } else if (group.key == options::VERSION) {
      // TODO:do version
    } else if (group.key == options::HELP) {
      // TODO:do some help
    } else if (group.key == options::LIST_ALL_TESTS) {
      // TODO:
    } else if (group.key == options::RUN_SOME_TESTS) {
      // TODO:
    } else if (group.key == options::EXCLUDE_SOME_TESTS) {
      // TODO:
    } else if (group.key == options::RUN_ALL_TESTS) {
      // TODO:
    } else if (group.key == options::UNKNOW) {
      // TODO:
    } else {
      // TODO:some error
    }

    std::cout << options_desc[group.key] << ">>>>>";
    for (const auto& __ : group.value) {
      std::cout << __ << ",";
    }
    std::cout << "\n";
  }

  std::cout << "error param:\n";
  for (const auto& _ : error_param_) {
    std::cout << _ << " ";
  }

  std::cout << "\n";
}

}  // namespace she_test
