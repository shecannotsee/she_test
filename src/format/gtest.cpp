#include "gtest.h"

#include "color.h"
#include "fmt.h"

she_test::format::gtest::gtest(const uint64_t test_number, const std::vector<std::vector<std::string>>& test_list)
    : test_number_(test_number), test_list_(test_list) {
  set_test_number(test_number_);
  gtest::global_start();
}

she_test::format::gtest::~gtest() {
  gtest::global_end();
}

void she_test::format::gtest::global_start() {
  using namespace color;
  fmt_println("{}[==========]{} Running {} tests.", GREEN_COLOR, RESET_COLOR, get_test_number());
  fmt_println("{}[----------]{} Global test environment set-up.", GREEN_COLOR, RESET_COLOR);
  fmt_print("{}[----------]{} {} tests from: ", GREEN_COLOR, RESET_COLOR, get_test_number());
  for (auto test : test_list_) {
    std::string test_name = [&]() {
      std::string name;
      for (auto test_name : test) {
        name += test_name + ".";
      }
      name.pop_back();
      return name;
    }();
    fmt_print("{}, ", test_name);
  }
  fmt_println("");
}

void she_test::format::gtest::global_end() {
  using namespace color;
  fmt_println("{}[----------]{} Global test environment tear-down.", GREEN_COLOR, RESET_COLOR);
  fmt_println("{}[==========]{} {} tests run. ({} ms total).", GREEN_COLOR, RESET_COLOR, get_test_number(),
              get_test_time());
  fmt_println("{}[  PASSED  ]{} {} tests", GREEN_COLOR, RESET_COLOR, get_test_number() - get_failed_tests());
}

void she_test::format::gtest::before_test_case(const std::string& test_name) {
  using namespace color;
  fmt_println("{}[ RUN      ]{} {}", GREEN_COLOR, RESET_COLOR, test_name);
  template_format::start_test_time();
}

void she_test::format::gtest::after_test_case(const std::string& test_name) {
  using namespace color;
  auto time = template_format::end_test_time();
  if (true) {
    fmt_println("{}[       OK ]{} {}({} ms)", GREEN_COLOR, RESET_COLOR, test_name, time);
  } else {
    fmt_println("{}[  FAILED  ]{} {}({} ms)", RED_COLOR, RESET_COLOR, test_name, time);
    add_failed_test_number();
  }
}
