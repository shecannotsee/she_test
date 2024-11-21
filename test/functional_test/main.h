#ifndef TEST_FUNCTIONAL_MAIN_H
#define TEST_FUNCTIONAL_MAIN_H

#include "../test_support.h"

namespace functional_test {

inline void run_tests() {
  test_support _("functional");
  // level.test
  // test1
  // level1.test
  // level1.level2.test
  // level1.level2.level3.test
  // level1.level2.level3.level4.test
  // level1.level2.level3.level4.level5.test
  // level1.level2.level3.level4.level5.level6.test

  {
    constexpr int argc = 1;
    const char* argv[argc]{"she_test_test"};
    she_test::run_all_test<>(argc, const_cast<char**>(argv));
  }

  {
    constexpr int argc = 3;
    const char* argv[argc]{"she_test_test", "-run", "level.test"};
    she_test::run_all_test<>(argc, const_cast<char**>(argv));
  }

  {
    constexpr int argc = 6;
    const char* argv[argc]{"she_test_test", "-run", "level.test", "test1", "-exclude", "level.test"};
    she_test::run_all_test<>(argc, const_cast<char**>(argv));
  }
}

}  // namespace functional_test

#endif  // TEST_FUNCTIONAL_MAIN_H
