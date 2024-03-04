//
// Created by shecannotsee on 24-3-4.
//

#ifndef TEMPLATE_SUPPORT_TEST_START_TEST_H
#define TEMPLATE_SUPPORT_TEST_START_TEST_H
#include <string>

#include "template_support/equal.h"

namespace template_support_test {

void check();

inline int run() {
  using namespace she_test;
  check();
  CHECK_EQUAL(1,2);
  CHECK_EQUAL("123","123");
  CHECK_EQUAL(1,2);
  return 0;
}

}  // namespace template_support_test

#endif  // TEMPLATE_SUPPORT_TEST_START_TEST_H
