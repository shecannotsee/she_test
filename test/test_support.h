#ifndef TEST_TEST_SUPPORT_H
#define TEST_TEST_SUPPORT_H

#include <she_test.h>

#include <string>
#include <utility>

struct test_support {
  explicit test_support(std::string module_name) : module_name_(std::move(module_name)) {
    printf("%s########## [%s] start! ##########\n%s", she_test::color::BLUE_COLOR, module_name_.c_str(),
           she_test::color::RESET_COLOR);
  }

  ~test_support() {
    printf("%s########## [%s] done! ##########\n\n%s", she_test::color::BLUE_COLOR, module_name_.c_str(),
           she_test::color::RESET_COLOR);
  }

 private:
  std::string module_name_;
};

#endif  // TEST_TEST_SUPPORT_H
