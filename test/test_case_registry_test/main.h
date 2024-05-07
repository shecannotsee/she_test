#ifndef TEST_CASE_REGISTRY_TEST_MAIN_H
#define TEST_CASE_REGISTRY_TEST_MAIN_H

#include <test_case_registry/register_center.h>

#include "../test_support.h"

namespace test_case_registry_test {

inline int run_test() {
  test_support _("test_case_registry_test");

  she_test::details::register_center<>::init_and_run();

  return 0;
}

}  // namespace test_case_registry_test

#endif  // TEST_CASE_REGISTRY_TEST_MAIN_H
