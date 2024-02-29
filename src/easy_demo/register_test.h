//
// Created by shecannotsee on 24-2-29.
//

#ifndef REGISTER_TEST_H
#define REGISTER_TEST_H

#include <functional>
#include <vector>

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
  // copy:off
  test_manager(const test_manager&)            = delete;
  test_manager& operator=(const test_manager&) = delete;
  // move:off
  test_manager(test_manager&&)            = delete;
  test_manager& operator=(test_manager&&) = delete;

 public:
  // register test function
  static void register_test(std::function<void()> testFunction) {
    instance().tests.push_back(testFunction);
  }

  // run
  static void run_all_tests() {
    for (auto test : instance().tests) {
      test();  // call test function
    }
  }

 private:
  test_manager() = default;

  static test_manager& instance() {
    static test_manager instance;
    return instance;
  }

  // test table
  std::vector<std::function<void()>> tests;
};

#endif //REGISTER_TEST_H
