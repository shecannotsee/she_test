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
  static command_line& getInstance() {
    static command_line instance;
    return instance;
  }

 private:
  // constructors
  command_line() = default;

  std::vector<details::parame_packages> ops_{};

 public:
  // Convert the parameter to a state
  void parse(int argc, char** argv);

  std::vector<details::parame_packages> get_ops() {
    auto ret = std::move(ops_);
    ops_.clear();
    return ret;
  }

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
