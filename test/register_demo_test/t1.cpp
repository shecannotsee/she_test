#include "register_demo.h"

#include <iostream>

// REGISTER_TEST(test_expansion) {
//   std::cout << "test_expansion\n";
// }

// This macro is equivalent to the following code

void test_expansion_test_function();

namespace {
struct test_expansion_register {
  test_expansion_register() {
    testing_only::register_demo::register_test(test_expansion_test_function);
  }
} test_expansion_register_instance;
}  // namespace

void test_expansion_test_function() {
  std::cout << "Running test_expansion...\n";
}
