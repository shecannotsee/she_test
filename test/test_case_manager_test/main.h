//
// Created by shecannotsee on 24-2-29.
//

#ifndef TEST_CASE_MANAGER_TEST_MAIN_H
#define TEST_CASE_MANAGER_TEST_MAIN_H
#include "../test_support.h"
#include "she_test.h"

namespace test_case_manager_test {

inline int run_test() {
  test_support _("test_case_manager_test");

  she_test::test_case_manager::add("zzz", "yyy", []() { return true; });

  she_test::test_case_manager::init();

  return 0;
}

}  // namespace test_case_manager_test

#endif  // TEST_CASE_MANAGER_TEST_MAIN_H
