#ifndef FUNCTIONAL_MAIN_H
#define FUNCTIONAL_MAIN_H

#include <she_test.h>

#include "../test_support.h"

namespace functional {

void run_tests() {
  test_support _("functional");
  // /level/test
  // /test1
  // /level1/test
  // /level1/level2/test
  // /level1/level2/level3/test
  // /level1/level2/level3/level4/test
  // /level1/level2/level3/level4/level5/test
  // /level1/level2/level3/level4/level5/level6/test

  {
    constexpr int argc = 1;
    const char* argv[]{"she_test_test"};
    she_test::run_all_test<>(argc, const_cast<char**>(argv));
  }
}

}  // namespace functional

#endif  // FUNCTIONAL_MAIN_H
