//
// Created by shecannotsee on 24-2-4.
//
#include <iostream>

#include "global_init.h"
#include "global_test_set.h"

void sampleTestFunction() {
  // Your test logic goes here
  std::cout << "Sample Test Function Executed!" << std::endl;
}

int main() {
  std::cout << GREEN_COLOR << "test start.\n" << RESET_COLOR;

  // Adding test cases
  she_test::test_case_manager(she_test::test_case_operator::ADD, "Suite1", "Test1", sampleTestFunction);
  // Add more test cases as needed

  // Running test cases
  she_test::test_case_manager(she_test::test_case_operator::RUN, "Suite1", "Test1");
  // Run more test cases as needed
  std::cout << GREEN_COLOR << "test Done.\n" << RESET_COLOR;
  return 0;
}
