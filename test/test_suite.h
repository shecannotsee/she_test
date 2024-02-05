//
// Created by shecannotsee on 24-2-5.
//

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "she_test.h"
#include "t1.h"

namespace she_test {
class test_suite {
 public:
  static void init() {
    test_case_manager::add("s1", "t1", example_right_test);
    test_case_manager::add("s1", "t2", throw_test);
  }
};
}  // namespace she_test

#endif  // TEST_SUITE_H
