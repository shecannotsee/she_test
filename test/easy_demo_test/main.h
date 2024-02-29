//
// Created by shecannotsee on 24-2-29.
//

#ifndef MAIN_H
#define MAIN_H

#include <easy_demo/register_test.h>

#include <iostream>

namespace easy_demo_test {

inline int run_test() {
  std::cout << "easy_demo_test start.\n";

  test_manager::run_all_tests();

  std::cout << "easy_demo_test Done.\n";
  return 0;
}

}  // namespace easy_demo_test

#endif  // MAIN_H
