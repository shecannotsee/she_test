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
using std::function;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

using test_function  = function<void()>;
using test_map       = unordered_map<string, test_function>;
using test_suite_map = unordered_map<string, test_map>;
static test_suite_map test_suites;

static vector<pair<string, string>> get_all_test_cases() {
  vector<pair<string, string>> all_test_cases;

  for (const auto& suite : test_suites) {
    const string& suite_name  = suite.first;
    const test_map& testSuite = suite.second;

    for (const auto& test : testSuite) {
      const string& test_name = test.first;

      all_test_cases.emplace_back(suite_name, test_name);
    }
  }

  return all_test_cases;
}

static void run(const string& suite_name, const string& test_name) {
  if (test_suites.find(suite_name) != test_suites.end()) {
    test_map& testSuite = test_suites[suite_name];
    // run test func
    if (testSuite.find(test_name) != testSuite.end()) {
      std::cout << "Running Test Case: " << suite_name << " - " << test_name << std::endl;
      const test_function& testFunc = testSuite[test_name];
      if (testFunc) {
        testFunc();  // Run the test function
      } else {
        std::cout << "test function is nullptr;\n";
      }
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
    const string& suite_name = test_case.first;
    const string& test_name  = test_case.second;
    run(suite_name, test_name);
  }
}

static void add(const string& suite_name, const string& test_name, const test_function& test_func = nullptr) {
  test_suites[suite_name][test_name] = test_func;
}

}  // namespace test_case_manager

}  // namespace she_test

#endif  // GLOBAL_INIT_H
