//
// Created by shecannotsee on 24-2-4.
//

#ifndef GLOBAL_INIT_H
#define GLOBAL_INIT_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace she_test {
enum class test_case_operator {
  ADD,
  RUN,
  GET_ALL,
};

namespace test_case_manager {
using test_function  = std::function<void()>;
using test_map       = std::unordered_map<std::string, test_function>;
using test_suite_map = std::unordered_map<std::string, test_map>;
static test_suite_map test_suites;

static std::vector<std::pair<std::string, std::string>> get_all_test_cases() {
  std::vector<std::pair<std::string, std::string>> all_test_cases;

  for (const auto& suite : test_suites) {
    const std::string& suite_name = suite.first;
    const test_map& testSuite     = suite.second;

    for (const auto& test : testSuite) {
      const std::string& test_name = test.first;

      all_test_cases.emplace_back(suite_name, test_name);
    }
  }

  return all_test_cases;
}

static void run(const std::string& suite_name, const std::string& test_name) {
  if (test_suites.find(suite_name) != test_suites.end()) {
    test_map& testSuite = test_suites[suite_name];
    // run test func
    if (testSuite.find(test_name) != testSuite.end()) {
      std::cout << "Running Test Case: " << suite_name << " - " << test_name << std::endl;
      const test_function& testFunc = testSuite[test_name];
      testFunc();  // Run the test function
    }
    // not found
    else {
      std::cerr << "Error: Test Case '" << test_name << "' not found in suite '" << suite_name << "'" << std::endl;
    }
  }
  // not found
  else {
    std::cerr << "Error: Test Suite '" << suite_name << "' not found" << std::endl;
  }
}

static void init() {
  const auto all_test_cases = get_all_test_cases();
  for (const auto& test_case : all_test_cases) {
    const std::string& suite_name = test_case.first;
    const std::string& test_name  = test_case.second;
    run(suite_name, test_name);
  }
}

static void add(const std::string& suite_name,
                const std::string& test_name,
                const std::function<void()>& test_func = nullptr) {
  test_suites[suite_name][test_name] = test_func;
}

}  // namespace test_case_manager

}  // namespace she_test

namespace she_test {

// 辅助类，用于注册测试用例
template <typename T>
struct TestRegistrar {
  TestRegistrar(const std::string& suite_name, const std::string& test_name, const std::function<void()>& test_func) {
    test_case_manager::add(suite_name, test_name, test_func);
  }
};

}  // namespace she_test

// 宏，用于定义测试用例
#define SHE_TEST(suite_name, test_name)                                                     \
  void she_test_##suite_name##_##test_name();                                               \
  static she_test::TestRegistrar<void (*)()> she_test_registrar_##suite_name##_##test_name( \
      #suite_name, #test_name, &she_test_##suite_name##_##test_name);                       \
  void she_test_##suite_name## _## test_name()

#endif  // GLOBAL_INIT_H
