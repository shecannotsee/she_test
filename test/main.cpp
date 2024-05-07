//
// Created by shecannotsee on 24-2-4.
//
#include "register_demo_test/main.h"

#include "command_line_parse_test/main.h"
#include "integrity_test/main.h"
#include "output_format_test/main.h"
#include "template_support_test/start_test.h"
#include "test_case_registry_test/main.h"

int main(int argc, char** argv) {
  command_line_parse_test::run_test();
  easy_demo_test::run_test();
  output_format_test::run_test();
  template_support_test::run_test();
  test_case_registry_test::run_test();
  integrity_test::run_test(argc,argv);
  return 0;
}
