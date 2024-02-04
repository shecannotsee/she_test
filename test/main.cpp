//
// Created by shecannotsee on 24-2-4.
//
#include <iostream>

#include "global_init.h"
#include "global_test_set.h"

int main() {
  std::cout << GREEN_COLOR << "test start.\n" << RESET_COLOR;

  she_test::test_case_manager::init();

  std::cout << GREEN_COLOR << "test Done.\n" << RESET_COLOR;
  return 0;
}
