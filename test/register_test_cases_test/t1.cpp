//
// Created by shecannotsee on 24-2-29.
//
#include <she_test.h>

bool register_test_cases_test() {
  return false;
}

namespace {
struct x {
  x() {
    she_test::details::register_center::add_test("zzz", "xxx", register_test_cases_test);
  }
} x_;
}  // namespace
