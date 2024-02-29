//
// Created by shecannotsee on 24-2-29.
//

#include <easy_demo/register_test.h>

#include <iostream>

REGISTER_TEST(my_test_case) {
  std::cout << "Running my_test_case..." << std::endl;
}

REGISTER_TEST(another_test_case) {
  std::cout << "Running another_test_case..." << std::endl;
}
