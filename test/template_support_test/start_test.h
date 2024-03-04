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
  return 0;
}

}  // namespace template_support_test

#endif  // TEMPLATE_SUPPORT_TEST_START_TEST_H
