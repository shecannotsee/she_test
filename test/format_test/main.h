#ifndef TEST_FORMAT_TEST_MAIN_H
#define TEST_FORMAT_TEST_MAIN_H

#include "../test_support.h"

namespace format_test {

inline void run_test() {
  test_support _("format");

  {
    she_test::format::gtest t1(3, {{"test", "test2", "test3"}});
    t1.before_test_case("level");
    [] {
      std::cout << "running...\n";
      return true;
    }();
    bool pass = true;
    t1.after_test_case("level", pass);
  }
  {
    she_test::format::style_v1 t2(3, {{"test", "test2", "test3"}});
    t2.before_test_case("level");
    [] {
      std::cout << "running...\n";
      return true;
    }();
    bool pass = true;
    t2.after_test_case("level", pass);
  }
}

}  // namespace format_test

#endif  // TEST_FORMAT_TEST_MAIN_H
