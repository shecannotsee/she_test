#ifndef INTEGRITY_TEST_MAIN_H
#define INTEGRITY_TEST_MAIN_H

#include "../test_support.h"
#include "she_test.h"

namespace integrity_test {

inline int run_test(int argc, char** argv) {
  test_support _("integrity_test");

  she_test::details::register_center<>::init_and_run(argc, argv);

  return 0;
}

}  // namespace integrity_test

#endif  // INTEGRITY_TEST_MAIN_H
