#include "start_test.h"

#include <template_support/equal.h>
#include <iostream>

void template_support_test::check() {
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