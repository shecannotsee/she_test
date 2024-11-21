#ifndef SHE_TEST_RUN_ALL_TEST_H
#define SHE_TEST_RUN_ALL_TEST_H

#include <iostream>

#include "command_line/parser.h"
#include "format/gtest.h"
#include "format/template_format.h"
#include "test_case_registry/multi_level_test_case.h"

namespace she_test {

namespace details {
void exec_version();
void exec_help();
void exec_list_all_tests();
void exec_run_some_tests(std::vector<std::vector<std::string>>& use, const std::vector<std::string>& op_value);
void exec_exclude_some_tests(std::vector<std::vector<std::string>>& use, const std::vector<std::string>& op_value);
void exec_run_all_tests(const std::vector<std::vector<std::string>>& all, std::vector<std::vector<std::string>>& use);
void exec_unknown(const parameter_pack& op);
}  // namespace details

template <typename format_type = format::gtest>
void run_all_test(int argc, char** argv) {
  using namespace she_test;
  using namespace she_test::details;
  // Get All test case
  const auto all_test_cases = multi_level_test_case::get_test_case_list();
  std::vector<std::vector<std::string>> use_test_cases;
  // parser
  auto ops = command_line::parse(argc, argv);
  // process command
  for (const auto& op : ops) {
    switch (op.key) {
      case options::VERSION: {
        exec_version();
        continue;
      }  // case options::VERSION
      case options::HELP: {
        exec_help();
        continue;
      }  // case options::HELP
      case options::LIST_ALL_TESTS: {
        exec_list_all_tests();
        continue;
      }  // case options::LIST_ALL_TESTS
      case options::RUN_SOME_TESTS: {
        exec_run_some_tests(use_test_cases, op.value);
        continue;
      }  // case options::RUN_SOME_TESTS
      case options::EXCLUDE_SOME_TESTS: {
        exec_exclude_some_tests(use_test_cases, op.value);
        continue;
      }  // case options::EXCLUDE_SOME_TESTS
      case options::RUN_ALL_TESTS: {
        exec_run_all_tests(all_test_cases, use_test_cases);
        continue;
      }  // case options::RUN_ALL_TESTS
      case options::UNKNOWN: {
        exec_unknown(op);
        continue;
      }  // case options::UNKNOWN
    }    // switch
  }      // for

  // Run test case
  format_type fmt(use_test_cases.size(), use_test_cases);
  for (const auto& test_case : use_test_cases) {
    auto test_case_format_string = [&]() {
      std::string string_name;
      for (auto& test_case_name : test_case) {
        string_name += test_case_name + ".";
      }
      string_name.pop_back();
      return string_name;
    }();
    fmt.before_test_case(test_case_format_string);
    bool pass = true;
    try {
      multi_level_test_case::run_test_case(test_case, pass);
    } catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
    }
    fmt.after_test_case(test_case_format_string, pass);
  }
}

}  // namespace she_test

#endif  // SHE_TEST_RUN_ALL_TEST_H
