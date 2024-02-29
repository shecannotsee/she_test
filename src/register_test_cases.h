//
// Created by shecannotsee on 24-2-29.
//

#ifndef REGISTER_TEST_CASES_H
#define REGISTER_TEST_CASES_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_case_manager.h"

namespace she_test {

namespace details {

namespace register_details {
using std::function;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
using namespace print_color;

using test_function  = function<bool()>;
using test_map       = unordered_map<string, test_function>;
using test_suite_map = unordered_map<string, test_map>;
}  // namespace register_details

using namespace register_details;

class register_center {
 public:
  // copy:off
  register_center(const register_center&)            = delete;
  register_center& operator=(const register_center&) = delete;
  // move:off
  register_center(register_center&&)            = delete;
  register_center& operator=(register_center&&) = delete;

 private:
  register_center() = default;

  static auto get_instance() -> register_center& {
    static register_center instance;
    return instance;
  }

  // test table
  test_case_manager::test_suite_map tests;

 public:
  static void add_test(const std::string& suite_name,
                       const std::string& test_name,
                       const test_function& test_func = nullptr) {
    get_instance().tests[suite_name][test_name] = test_func;
  }

  static void init() {
    const auto all_test_cases = get_all_test_cases();
    for (const auto& test_case : all_test_cases) {
      const std::string& suite_name = test_case.first;
      const std::string& test_name  = test_case.second;
      run(suite_name, test_name);
    }
  }

 private:
  static auto get_all_test_cases() -> vector<pair<string, string>> {
    vector<pair<string, string>> all_test_cases;

    for (const auto& suite : get_instance().tests) {
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
    if (get_instance().tests.find(suite_name) != get_instance().tests.end()) {
      test_map& testSuite = get_instance().tests[suite_name];
      // run test func
      if (testSuite.find(test_name) != testSuite.end()) {
        std::cout << YELLOW_COLOR << "[Ready to Running] >>> " << suite_name << " - " << test_name << "\n"
                  << RESET_COLOR;
        const test_function& testFunc = testSuite[test_name];
        // Run result processing
        bool run_success = false;
        if (testFunc) {
          try {
            run_success = testFunc();  // Run the test function
          } catch (...) {
            run_success = false;
          }
        } else {
          std::cout << RED_COLOR << "test function is nullptr\n" << RESET_COLOR;
        }
        if (run_success)
          std::cout << GREEN_COLOR << "[Running done,res] >>> SUCCESS\n\n" << RESET_COLOR;
        else
          std::cout << RED_COLOR << "[Running done,res] >>> FAILED\n\n" << RESET_COLOR;

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
};

}  // namespace details
}  // namespace she_test

#endif  // REGISTER_TEST_CASES_H
