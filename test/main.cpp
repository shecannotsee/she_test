//
// Created by shecannotsee on 24-2-4.
//
#include "register_demo_test/main.h"

#include <she_test.h>

#include "command_line_parse_test/main.h"
#include "output_format_test/main.h"
#include "register_test_cases_test/main.h"
#include "template_support_test/start_test.h"
#include "test_case_manager_test/main.h"

int main(int argc, char** argv) {
  she_test::command_line::getInstance().parse(argc, argv);
  easy_demo_test::run_test();
  test_case_manager_test::run_test();
  register_test_cases_test::run_test();
  output_format_test::run_test();
  template_support_test::run_test();
  return 0;
}
