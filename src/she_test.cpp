#include "she_test.h"

#include "test_case_registry/multi_level_test_case.h"

namespace {
void exec_version() {
  std::cout << "she_test version " << she_test::details::version << std::endl;
}

void exec_help() {
  std::cout << she_test::details::help_message << std::endl;
}

void exec_list_all_tests() {
  for (const auto& multi_level_name : multi_level_test_case::get_test_case_list()) {
    for (int i = 0; i < multi_level_name.size(); i++) {
      std::cout << multi_level_name[i];
      if (i != multi_level_name.size() - 1) {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}

void exec_run_some_tests() {
}

void exec_exclude_some_tests() {
}

void exec_run_all_tests() {
}

void exec_unknown(const she_test::details::parame_packages& op) {
  std::cout << "error options:\n";
  for (const auto& error_options : op.value) {
    std::cout << error_options << std::endl;
  }
}
}  // namespace

void she_test::run_all_test(int argc, char** argv) {
  using namespace she_test;
  using namespace she_test::details;
  // parser
  parser::get_instance().parse(argc, argv);
  // process command
  for (const auto& op : parser::get_instance().get_ops()) {
    switch (op.key) {
      case options::VERSION: {
        exec_version();
        return;
      }  // case options::VERSION
      case options::HELP: {
        exec_help();
        return;
      }  // case options::HELP
      case options::LIST_ALL_TESTS: {
        exec_list_all_tests();
        return;
      }  // case options::LIST_ALL_TESTS
      case options::RUN_SOME_TESTS: {
        exec_run_some_tests();
        return;
      }  // case options::RUN_SOME_TESTS
      case options::EXCLUDE_SOME_TESTS: {
        exec_exclude_some_tests();
        return;
      }  // case options::EXCLUDE_SOME_TESTS
      case options::RUN_ALL_TESTS: {
        exec_run_all_tests();
        return;
      }  // case options::RUN_ALL_TESTS
      case options::UNKNOWN: {
        exec_unknown(op);
        return;
      }  // case options::UNKNOWN
      default: {
        std::cout << "Unknown error\n";
        return;
      }  // default
    }    // switch
  }      // for
}
