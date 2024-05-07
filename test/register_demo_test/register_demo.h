/*
 * The file is just a simple example
 */

#ifndef SHE_TEST_REGISTER_TEST_H
#define SHE_TEST_REGISTER_TEST_H

#include <functional>
#include <vector>

// just to show how to register
#define REGISTER_TEST(test_name)                                             \
  void test_name##_test_function();                                          \
  namespace {                                                                \
  struct test_name##_register {                                              \
    test_name##_register() {                                                 \
      testing_only::register_demo::register_test(test_name##_test_function); \
    }                                                                        \
  } test_name##_register_instance;                                           \
  }                                                                          \
  void test_name##_test_function()

namespace testing_only {

class register_demo {
 public:
  // copy:off
  register_demo(const register_demo&)            = delete;
  register_demo& operator=(const register_demo&) = delete;
  // move:off
  register_demo(register_demo&&)            = delete;
  register_demo& operator=(register_demo&&) = delete;

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
  register_demo() = default;

  static register_demo& instance() {
    static register_demo instance;
    return instance;
  }

  // test table
  std::vector<std::function<void()>> tests;
};
}  // namespace testing_only

#endif  // SHE_TEST_REGISTER_TEST_H
