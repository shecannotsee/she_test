#ifndef SHE_TEST_TEST_CASE_H
#define SHE_TEST_TEST_CASE_H

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace she_test {

namespace details {
using namespace std;
using test_function    = function<bool()>;
using test_suite_table = unordered_map<string, unordered_map<string, test_function>>;
}  // namespace details

class test_case {
  static auto get_instance() -> test_case& {
    static test_case instance;
    return instance;
  }

  details::test_suite_table tests_;

 public:
  static void add(const std::string& suite_name,
                  const std::string& test_name,
                  const details::test_function& test_func = nullptr) {
    get_instance().tests_[suite_name][test_name] = test_func;
  }

  static auto get_all() -> std::vector<std::tuple<std::string, std::string>> {
    std::vector<std::tuple<std::string, std::string>> all_test_cases;

    for (const auto& suite : get_instance().tests_) {
      const std::string& suite_name                                            = suite.first;
      const std::unordered_map<std::string, details::test_function>& testSuite = suite.second;

      for (const auto& test : testSuite) {
        const std::string& test_name = test.first;

        all_test_cases.emplace_back(suite_name, test_name);
      }
    }

    return all_test_cases;
  }

  template <typename output_format_type>
  static void run(const std::string& suite_name, const std::string& test_name) {
    output_format_type format;
    // There are no test suite
    if (get_instance().tests_.find(suite_name) == get_instance().tests_.end()) {
      format.NO_TEST_SUITE(suite_name);
      return;
    }

    // There are no test case under test suite
    if (get_instance().tests_[suite_name].find(test_name) == get_instance().tests_[suite_name].end()) {
      format.NO_TEST_CASE(test_name);
      return;
    }
    // Run test case and check
    const auto& func = get_instance().tests_[suite_name][test_name];
    format.READY_TO_RACE(suite_name, test_name, func);
  }
};
}  // namespace she_test

#endif  // SHE_TEST_TEST_CASE_H
