//
// Created by shecannotsee on 24-2-29.
//

#ifndef OUTPUT_FORMAT_TEST_MAIN_H
#define OUTPUT_FORMAT_TEST_MAIN_H

#include <output_format/gtest_format.h>

#include <thread>

#include "output_format/s_test_v1.h"

namespace output_format_test {

inline int run_test() {
  {
    she_test::output_format::gtest t1;
    t1.READY_TO_RACE("gtest_format", "true", []() -> bool {
      std::cout << "running...\n";
      return true;
    });
    t1.READY_TO_RACE("gtest_format", "false", []() -> bool {
      std::cout << "ready to sleep...\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      return false;
    });
  }
  {
    she_test::output_format::s_test_v1 t2;

    t2.READY_TO_RACE("s_test_v1_format", "true", []() -> bool {
      std::cout << "running...\n";
      return true;
    });
    t2.READY_TO_RACE("s_test_v1_format", "false", []() -> bool {
      std::cout << "ready to sleep...\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      return false;
    });
  }

  return 0;
}

}  // namespace output_format_test

#endif  // OUTPUT_FORMAT_TEST_MAIN_H
