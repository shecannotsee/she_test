#ifndef SHE_TEST_REGISTER_CENTER_H
#define SHE_TEST_REGISTER_CENTER_H

#include <iostream>

#include "../command_line/options.h"
#include "../command_line/parser.h"
#include "../format/gtest.h"
#include "test_case.h"

namespace she_test {

namespace details {

template <typename T = format::gtest>
class register_center {
 public:
  static void add_test(const std::string& suite_name,
                       const std::string& test_name,
                       const details::test_function& test_func = nullptr);

  static void init_and_run(int argc = 1, char** argv = nullptr);
};

}  // namespace details

}  // namespace she_test

#include "register_center_impl.h"

#define SHE_TEST(test_suite_name, test_name)                                                 \
  namespace test_suite_name {                                                                \
  bool test_name();                                                                          \
  struct test_name##_register {                                                              \
    test_name##_register() {                                                                 \
      she_test::details::register_center<>::add_test(#test_suite_name, #test_name, test_name); \
    }                                                                                        \
  } test_name##_instance;                                                                    \
  }                                                                                          \
  bool test_suite_name::test_name()

#endif  // SHE_TEST_REGISTER_CENTER_H
