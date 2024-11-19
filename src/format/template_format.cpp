#include "template_format.h"

she_test::format::template_format::template_format(const std::vector<std::tuple<std::string, std::string>>& list) {
  /* Get suite snumber */
  {
    std::unordered_map<std::string, int> unique_elements;
    for (const auto& tuple : list) {
      const std::string& element = std::get<0>(tuple);
      unique_elements[element]++;
    }
    for (const auto& pair : unique_elements) {
      module_name += pair.first + "(" + std::to_string(pair.second) + ") ";
      ++total_number_of_suites;
    }
  }
  /* Get test case number */
  total_number_of_tests = list.size();
}

int she_test::format::template_format::run_and_check(const details::test_function& waiting_to_run) {
  if (waiting_to_run) {
    const auto start = std::chrono::high_resolution_clock::now();
    if (!waiting_to_run()) {
      ++failed_tests;
    }
    const auto end      = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count();
  }
  return 0;
}