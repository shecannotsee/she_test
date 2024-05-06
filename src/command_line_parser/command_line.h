#ifndef SHE_TEST_COMMAND_LINE_H
#define SHE_TEST_COMMAND_LINE_H

#include <vector>

#include "options.h"

namespace she_test {

class command_line {
 public:
  static command_line& getInstance() {
    static command_line instance;
    return instance;
  }

 private:
  // constructors
  command_line() = default;

  struct one_to_many {
    options key{};
    std::vector<std::string> value{};
  };

  std::vector<one_to_many> ops_{};
  std::vector<std::string> error_param_{};

  void exec();

 public:
  void parse(int argc, char** argv);
};

}  // namespace she_test

#endif  // SHE_TEST_COMMAND_LINE_H
