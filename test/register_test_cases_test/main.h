//
// Created by shecannotsee on 24-2-29.
//

#ifndef REGISTER_TEST_CASES_TEST_MAIN_H
#define REGISTER_TEST_CASES_TEST_MAIN_H

#include <she_test.h>

namespace register_test_cases_test {

inline int run_test() {
  std::cout << "register_test_cases_test start.\n";
  she_test::details::register_center::init_and_run();
  std::cout << "register_test_cases_test done.\n";
  return 0;
}

}  // namespace register_test_cases_test

#endif  // REGISTER_TEST_CASES_TEST_MAIN_H
