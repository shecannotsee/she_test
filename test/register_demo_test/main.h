#ifndef TEST_REGISTER_DEMO_TEST_MAIN_H
#define TEST_REGISTER_DEMO_TEST_MAIN_H

#include "../test_support.h"
#include "register_demo.h"

namespace register_demo_test {

inline void run_test() {
  test_support _("easy_demo_test: register_demo");

  testing_only::register_demo::run_all_tests();
}

}  // namespace easy_demo_test

#endif  // TEST_REGISTER_DEMO_TEST_MAIN_H
