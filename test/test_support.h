#ifndef SHE_TEST_TEST_SUPPORT_H
#define SHE_TEST_TEST_SUPPORT_H

#include <format/color.h>

#include <string>

struct test_support {
  explicit test_support(const std::string& module_name) : module_name_(module_name) {
    printf("%s########## [%s] start! ##########\n%s", she_test::color::BLUE_COLOR,module_name_.c_str(),she_test::color::RESET_COLOR);
  }

  ~test_support() {
    printf("%s########## [%s] done! ##########\n\n%s", she_test::color::BLUE_COLOR,module_name_.c_str(),she_test::color::RESET_COLOR);
  }

 private:
  std::string module_name_;
};

#endif  // SHE_TEST_TEST_SUPPORT_H
