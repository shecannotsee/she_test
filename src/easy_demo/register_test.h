//
// Created by shecannotsee on 24-2-29.
//

#ifndef REGISTER_TEST_H
#define REGISTER_TEST_H

#include <functional>
#include <vector>

using test_function = std::function<void()>;
class test_manager;

// 定义一个宏，用于注册测试函数
#define REGISTER_TEST(test_name)                              \
  void test_name##_test_function();                           \
  namespace {                                                 \
  struct test_name##_register {                               \
    test_name##_register() {                                  \
      test_manager::register_test(test_name##_test_function); \
    }                                                         \
  } test_name##_register_instance;                            \
  }                                                           \
  void test_name##_test_function()

class test_manager {
 public:
  // 注册测试函数的静态方法
  static void register_test(test_function testFunction) {
    instance().tests.push_back(testFunction);
  }

  // 运行所有注册的测试函数
  static void run_all_tests() {
    for (auto test : instance().tests) {
      test();  // 调用测试函数
    }
  }

 private:
  // 单例模式，保证唯一实例
  static test_manager& instance() {
    static test_manager instance;
    return instance;
  }

  // 存储注册的测试函数
  std::vector<test_function> tests;
};

#endif //REGISTER_TEST_H
