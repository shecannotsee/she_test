#include "style_v1.h"

#include "color.h"
#include "fmt.h"

she_test::format::style_v1::style_v1(uint64_t test_number, const std::vector<std::vector<std::string>>& test_list)
    : test_number_(test_number), test_list_(test_list) {
  set_test_number(test_number_);
  style_v1::global_start();
}

she_test::format::style_v1::~style_v1() {
  style_v1::global_end();
}

void she_test::format::style_v1::global_start() {
  using namespace color;
  fmt_println("{}[she_test]{} Framework begins testing...", PURPLE_COLOR, RESET_COLOR);
  fmt_println("{}[she_test]{} ...", PURPLE_COLOR, RESET_COLOR);
}

void she_test::format::style_v1::global_end() {
  using namespace color;
  fmt_println("{}[she_test]{} All test cases have ended running.", PURPLE_COLOR, RESET_COLOR);
  fmt_println("{}[she_test] >> {}{} tests ran. ({} ms total)", PURPLE_COLOR, RESET_COLOR, test_number_,
              template_format::get_test_time());
  fmt_println("{}[she_test] >> {} PASSED {} tests", PURPLE_COLOR, RESET_COLOR,
              template_format::get_test_number() - template_format::get_failed_tests());
}

void she_test::format::style_v1::before_test_case(const std::string& test_name) {
  using namespace color;
  fmt_println("{}[she_test] READY TO RACE...>> {}{}", YELLOW_COLOR, RESET_COLOR, test_name);
  template_format::start_test_time();
}

void she_test::format::style_v1::after_test_case(const std::string& test_name, bool pass) {
  using namespace color;
  auto time = template_format::end_test_time();
  if (pass) {
    fmt_println("{}[she_test] RACE COMPLETED. >> SUCCESS({} ms){}", GREEN_COLOR, time, RESET_COLOR);
  } else {
    fmt_println("{}[she_test] RACE COMPLETED. >> FAILED({} ms){}", RED_COLOR, time, RESET_COLOR);
    add_failed_test_number();
  }
}
