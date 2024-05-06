#ifndef SHE_TEST_REGISTER_CENTER_H
#define SHE_TEST_REGISTER_CENTER_H

#include "../output_format/gtest_format.h"
#include "test_case.h"

namespace she_test {

namespace details {

class register_center {
 public:
  static void add_test(const std::string& suite_name,
                       const std::string& test_name,
                       const details::test_function& test_func = nullptr) {
    test_case::add(suite_name, test_name, test_func);
  }
  static void init_and_run(int argc = 1, char** argv = nullptr) {
    const auto all_test = test_case::get_all();
    // TODO:filter from command_line

    std::vector<std::tuple<std::string, std::string>> result = all_test;
    ;
    for (const auto& _ : result) {
      test_case::run<output_format::gtest>(std::get<0>(_), std::get<1>(_));
    }
  }
};

}  // namespace details

}  // namespace she_test

#define SHE_TEST(test_suite_name, test_name)                                                 \
  namespace test_suite_name {                                                                \
  bool test_name();                                                                          \
  struct test_name##_register {                                                              \
    test_name##_register() {                                                                 \
      she_test::details::register_center::add_test(#test_suite_name, #test_name, test_name); \
    }                                                                                        \
  } test_name##_instance;                                                                    \
  }                                                                                          \
  bool test_suite_name::test_name()

#endif  // SHE_TEST_REGISTER_CENTER_H
