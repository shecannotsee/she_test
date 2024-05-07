#ifndef SHE_TEST_COMMAND_LINE_H
#define SHE_TEST_COMMAND_LINE_H

#include <functional>
#include <stdexcept>
#include <vector>

#include "options.h"

namespace she_test {

namespace details {
struct parame_packages {
  options key{};
  std::vector<std::string> value{};
};
}  // namespace details

class command_line {
 public:
  static command_line& get_instance() {
    static command_line instance;
    return instance;
  }

 private:
  // constructors
  command_line() = default;

  std::vector<details::parame_packages> ops_{};

 public:
  // Convert the parameter to a state
  void parse(int argc, char** argv) {
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
        details::parame_packages error_temp;
        error_temp.key = details::options::UNKNOW;
        error_temp.value.emplace_back(args[i]);
        ops_.emplace_back(error_temp);
      }
    }
  }

  // Use after parsing(this->parse)
  std::vector<details::parame_packages> get_ops() {
    auto ret = std::move(ops_);
    ops_.clear();
    return ret;
  }

  // Check the validity of the test name
  static auto split_suite_name_and_test_case(const std::string& input) -> std::tuple<std::string, std::string> {
    size_t pos = input.find('.');
    if (pos != std::string::npos) {
      std::string first  = input.substr(0, pos);
      std::string second = input.substr(pos + 1);
      return std::make_tuple(first, second);
    }
    std::string error_message = "error param:" + input;
    throw std::runtime_error(error_message);
  }
};

}  // namespace she_test

#endif  // SHE_TEST_COMMAND_LINE_H
