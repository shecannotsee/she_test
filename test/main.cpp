//
// Created by shecannotsee on 24-2-4.
//
#include "register_demo_test/main.h"

#include <she_test.h>

#include <iostream>

#include "register_test_cases_test/main.h"
#include "test_case_manager_test/main.h"

int main() {
  easy_demo_test::run_test();
  test_case_manager_test::run_test();
  register_test_cases_test::run_test();
  return 0;
}
