//
// Created by shecannotsee on 24-2-29.
//

#ifndef OUTPUT_FORMAT_TEST_MAIN_H
#define OUTPUT_FORMAT_TEST_MAIN_H

#include <output_format/gtest_format.h>

#include <thread>

namespace output_format_test {

inline int run_test() {
  she_test::output_format::gtest t;
  t.READY_TO_RACE("output_format_test", "true", []() -> bool {
    std::cout << "running...\n";
    return true;
  });
  t.READY_TO_RACE("output_format_test", "false", []() -> bool {
    std::cout << "ready to sleep...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return false;
  });

  return 0;
}

}  // namespace output_format_test

#endif  // OUTPUT_FORMAT_TEST_MAIN_H
