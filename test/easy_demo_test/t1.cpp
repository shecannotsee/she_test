//
// Created by shecannotsee on 24-2-29.
//

#include <easy_demo/register_test.h>

#include <iostream>

void aaaaaa_TestFunction();

namespace {
struct aaaaaaRegister {
  aaaaaaRegister() {
    test_manager::register_test(aaaaaa_TestFunction);
  }
} aaaaaaRegisterInstance;
}  // namespace

void aaaaaa_TestFunction() {
  std::cout << "aaaaa\n";
}
