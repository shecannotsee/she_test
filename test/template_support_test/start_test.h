#ifndef TEMPLATE_SUPPORT_TEST_START_TEST_H
#define TEMPLATE_SUPPORT_TEST_START_TEST_H
#include <iostream>
#include <string>

#include "../test_support.h"
#include "test_tools/equal.h"

namespace template_support_test {

void check(){
  using namespace she_test;
  std::cout << std::boolalpha;
  // 测试多个值是否相等
  std::cout << "Are all values equal? " << check_equal<int>(1, 2) << std::endl;
  std::cout << "Are all values equal? " << check_equal<int>(1, 2, 3) << std::endl;
  std::cout << "Are all values equal? " << check_equal<std::string>("123", std::string("123"), std::string("1234"))
            << std::endl;
  std::cout << "Are all values equal? " << check_equal<const char*>("1", "1") << std::endl;
  // std::cout << "Are all values equal? " << check_equal<int>(1) << std::endl;  // Will cause compilation errors

}

inline int run_test() {
  test_support _("template_support_test");

  using namespace she_test;
  check();
  CHECK_EQUAL(1,2);
  CHECK_EQUAL("123","123");
  CHECK_EQUAL(1,2);
  return 0;
}

}  // namespace template_support_test

#endif  // TEMPLATE_SUPPORT_TEST_START_TEST_H
