#ifndef TEST_TEST_TOOLS_TEST_MAIN_H
#define TEST_TEST_TOOLS_TEST_MAIN_H

#include <iostream>
#include <string>

#include "../test_support.h"

namespace test_tools_test {

inline void run_test() {
  test_support _("test_tools");

  using namespace she_test;
  std::cout << std::boolalpha;
  // 测试多个值是否相等
  std::cout << "Are all values equal? " << check_equal<int>(1, 2) << std::endl;
  std::cout << "Are all values equal? " << check_equal<int>(1, 2, 3) << std::endl;
  std::cout << "Are all values equal? " << check_equal<std::string>("123", std::string("123"), std::string("1234"))
            << std::endl;
  std::cout << "Are all values equal? " << check_equal<const char*>("1", "1") << std::endl;
}

}  // namespace test_tools_test

#endif  // TEST_TEST_TOOLS_TEST_MAIN_H
