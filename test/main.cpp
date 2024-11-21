#include "register_demo_test/main.h"

#include "command_line_parse_test/main.h"
#include "format/main.h"
#include "functional/main.h"
#include "test_tools/main.h"

int main() {
  easy_demo_test::run_test();
  command_line_parse_test::run_test();
  format::run_test();
  test_tools::run_test();
  functional::run_tests();
  return 0;
}
