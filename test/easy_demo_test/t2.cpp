//
// Created by shecannotsee on 24-2-29.
//

#include <easy_demo/register_test.h>

#include <iostream>

// 使用宏注册测试函数
REGISTER_TEST(MyTestCase) {
  // 进行测试
  std::cout << "Running MyTestCase..." << std::endl;
  // 添加测试代码
  // 比如：ASSERT_EQ(2 + 2, 4);
}

REGISTER_TEST(AnotherTestCase) {
  // 进行测试
  std::cout << "Running AnotherTestCase..." << std::endl;
  // 添加测试代码
  // 比如：ASSERT_TRUE(some_condition);
}
