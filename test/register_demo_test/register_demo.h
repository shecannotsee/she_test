#ifndef TEST_REGISTER_DEMO_TEST_REGISTER_DEMO_H
#define TEST_REGISTER_DEMO_TEST_REGISTER_DEMO_H

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

  // register test function
  static void register_test(const std::function<void()>& testFunction) {
    instance().tests.push_back(testFunction);
  }

  // run
  static void run_all_tests() {
    for (const auto& test : instance().tests) {
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

#endif  // TEST_REGISTER_DEMO_TEST_REGISTER_DEMO_H
