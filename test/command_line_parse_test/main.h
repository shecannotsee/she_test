//
// Created by shecannotsee on 24-5-6.
//

#ifndef COMMAND_LINE_PARSE_TEST_MAIN_H
#define COMMAND_LINE_PARSE_TEST_MAIN_H

namespace command_line_parse_test {

inline int run_test() {
  int argc = 2;
  char* argv[]{"she_test_test","-version"};
  she_test::command_line::getInstance().parse(argc, argv);

  return 0;
}
}  // namespace command_line_parse_test

#endif  // COMMAND_LINE_PARSE_TEST_MAIN_H
