#include "register_demo_test/main.h"
#include "command_line_test/main.h"
#include "format_test/main.h"
#include "functional_test/main.h"
#include "test_tools_test/main.h"

int main() {
  register_demo_test::run_test();
  command_line_test::run_test();
  format_test::run_test();
  test_tools_test::run_test();
  functional_test::run_tests();
  return 0;
}
