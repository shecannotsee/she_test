//
// Created by shecannotsee on 24-2-29.
//

#ifndef REGISTER_TEST_CASES_TEST_MAIN_H
#define REGISTER_TEST_CASES_TEST_MAIN_H

#include <she_test.h>
#include "../test_support.h"

namespace register_test_cases_test {

inline int run_test() {
  test_support _("register_test_cases_test");
  she_test::details::register_center::init_and_run();
  return 0;
}

}  // namespace register_test_cases_test

#endif  // REGISTER_TEST_CASES_TEST_MAIN_H
