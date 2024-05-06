//
// Created by shecannotsee on 24-2-29.
//

#ifndef EASY_DEMO_TEST_MAIN_H
#define EASY_DEMO_TEST_MAIN_H

#include <register_demo/register_demo.h>

#include <iostream>
#include "../test_support.h"

namespace easy_demo_test {

inline int run_test() {
  test_support _("easy_demo_test: register_demo");

  testing_only::register_demo::run_all_tests();

  return 0;
}

}  // namespace easy_demo_test

#endif  // EASY_DEMO_TEST_MAIN_H
