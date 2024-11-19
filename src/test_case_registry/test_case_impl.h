#ifndef SHE_TEST_TEST_CASE_IMPL_H
#define SHE_TEST_TEST_CASE_IMPL_H

template <typename output_format_type>
void she_test::test_case::run_all(const std::vector<std::tuple<std::string, std::string>>& list) {
  output_format_type format(list);
  for (const auto& test_case : list) {
    run<output_format_type>(std::get<0>(test_case), std::get<1>(test_case), std::forward<output_format_type>(format));
  }
}

template <typename output_format_type>
void she_test::test_case::run(const std::string& suite_name,
                              const std::string& test_name,
                              output_format_type&& format) {
  // There are no test suite
  if (get_instance().tests_.find(suite_name) == get_instance().tests_.end()) {
    format.NO_TEST_SUITE(suite_name);
    return;
  }

  // There are no test case under test suite
  if (get_instance().tests_[suite_name].find(test_name) == get_instance().tests_[suite_name].end()) {
    format.NO_TEST_CASE(suite_name, test_name);
    return;
  }

  // Run test case and check
  const auto& func = get_instance().tests_[suite_name][test_name];
  format.READY_TO_RACE(suite_name, test_name, func);
}

#endif  // SHE_TEST_TEST_CASE_IMPL_H
