//
// Created by shecannotsee on 24-2-4.
//
#include <iostream>

#include "she_test.h"
#include "test_suite.h"

int main() {
  using namespace print_color;
  std::cout << GREEN_COLOR << "test start.\n" << RESET_COLOR;

  she_test::test_suite::init();
  she_test::test_case_manager::init();

  std::cout << GREEN_COLOR << "test Done.\n" << RESET_COLOR;
  return 0;
}
