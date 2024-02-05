//
// Created by shecannotsee on 24-2-5.
//
#include "t1.h"

#include <iostream>

bool example_right_test() {
  std::cout << "example_test" << std::endl;
  return true;
}

bool throw_test() {
  throw std::runtime_error("throw_test");
}
