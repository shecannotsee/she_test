//
// Created by shecannotsee on 24-2-29.
//

#ifndef TEST_CASE_MANAGER_TEST_MAIN_H
#define TEST_CASE_MANAGER_TEST_MAIN_H
#include "she_test.h"

namespace test_case_manager_test {

inline int run_test() {
  std::cout << "test_case_manager_test start.\n";

  she_test::test_case_manager::add("zzz", "yyy", []() {
    return true;
  });

  she_test::test_case_manager::init();

  std::cout << "test_case_manager_test done.\n";
  return 0;
}

}  // namespace test_case_manager_test

#endif  // TEST_CASE_MANAGER_TEST_MAIN_H
