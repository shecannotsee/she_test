//
// Created by shecannotsee on 24-2-29.
//

#ifndef OUTPUT_FORMAT_TEST_MAIN_H
#define OUTPUT_FORMAT_TEST_MAIN_H

#include <format/gtest.h>

#include <thread>

#include "../test_support.h"
#include "format/style_v1.h"

namespace format {

inline int run_test() {
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

  return 0;
}

}  // namespace format

#endif  // OUTPUT_FORMAT_TEST_MAIN_H
