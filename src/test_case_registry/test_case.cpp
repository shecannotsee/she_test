#include "test_case.h"

auto she_test::test_case::get_instance() -> test_case& {
  static test_case instance;
  return instance;
}

void she_test::test_case::add(const std::string& suite_name,
                              const std::string& test_name,
                              const details::test_function& test_func) {
  get_instance().tests_[suite_name][test_name] = test_func;
}

auto she_test::test_case::get_all() -> std::vector<std::tuple<std::string, std::string>> {
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
