//
// Created by shecannotsee on 24-2-4.
//

#ifndef GLOBAL_INIT_H
#define GLOBAL_INIT_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

namespace she_test {
enum class test_case_operator {
  ADD,
  RUN,
};

static void test_case_manager(const test_case_operator op,
                              const std::string& suite_name,
                              const std::string& test_name,
                              const std::function<void()>& test_func = nullptr) {
  using namespace std;
  using test_function  = function<void()>;
  using test_map       = unordered_map<string, test_function>;
  using test_suite_map = unordered_map<string, test_map>;
  static test_suite_map test_suites;
  // just format
  if (0) {
    ;
  }
  // add
  else if (op == test_case_operator::ADD) {
    test_suites[suite_name][test_name] = test_func;
  }
  // run
  else if (op == test_case_operator::RUN) {
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
}

}  // namespace she_test

#endif  // GLOBAL_INIT_H
