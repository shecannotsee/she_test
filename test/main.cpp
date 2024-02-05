//
// Created by shecannotsee on 24-2-4.
//
#include <iostream>

#include "she_test.h"
#include "test_suite.h"

int main() {
  she_test::test_suite::init();
  she_test::test_case_manager::init();
  return 0;
}
