#ifndef SHE_TEST_REGISTER_CENTER_H
#define SHE_TEST_REGISTER_CENTER_H

#include <iostream>

#include "../command_line_parser/command_line.h"
#include "../command_line_parser/options.h"
#include "../output_format/gtest_format.h"
#include "test_case.h"

namespace she_test {

namespace details {

template<typename T = output_format::gtest>
class register_center {
 public:
  static void add_test(const std::string& suite_name,
                       const std::string& test_name,
                       const details::test_function& test_func = nullptr) {
    test_case::add(suite_name, test_name, test_func);
  }

  static void init_and_run(int argc = 1, char** argv = nullptr) {
    const auto all_test = test_case::get_all();
    std::vector<std::tuple<std::string, std::string>> run_list;
    // filter from command_line
    command_line::get_instance().parse(argc, argv);
    for (const auto& op : command_line::get_instance().get_ops()) {
      switch (op.key) {
        case options::VERSION: {
          std::cout << "she_test version " << version << std::endl;
          return;
        }
        case options::HELP: {
          std::cout << help_message << std::endl;
          return;
        }
        case options::LIST_ALL_TESTS: {
          for (const auto& test : test_case::get_all()) {
            std::cout << std::get<0>(test) << "." << std::get<1>(test) << std::endl;
          }
          return;
        }
        case options::RUN_SOME_TESTS: {
          for (const auto& test_cases : op.value) {
            try {
              auto ret = command_line::split_suite_name_and_test_case(test_cases);
              run_list.emplace_back(std::get<0>(ret), std::get<1>(ret));
            } catch (const std::runtime_error& ex) {
              std::cout << "The format is incorrect or does not exist :" << ex.what() << std::endl;
            }
          }
          break;
        }
        case options::EXCLUDE_SOME_TESTS: {
          if (run_list.empty()) {
            run_list = all_test;
          }
          std::cout << "exclude:\n";
          for (const auto& test_cases : op.value) {
            try {
              auto ret = command_line::split_suite_name_and_test_case(test_cases);
              for (int i = 0; i < run_list.size(); ++i) {
                bool exclude_cond =
                    (std::get<0>(run_list[i]) == std::get<0>(ret)) && (std::get<1>(run_list[i]) == std::get<1>(ret));
                if (exclude_cond) {
                  run_list.erase(run_list.begin() + i);
                  break;
                }
              }
            } catch (const std::runtime_error& ex) {
              std::cout << "The format is incorrect or does not exist :" << ex.what() << std::endl;
            }
          }
          break;
        }
        case options::RUN_ALL_TESTS: {
          run_list = all_test;
          break;
        }
        case options::UNKNOW: {
          std::cout << "error options:\n";
          for (const auto& error_options : op.value) {
            std::cout << error_options << std::endl;
          }
          return;
        }
        default: {
          std::cout << "Unknown error\n";
          return;
        }
      }  // switch
    }
    test_case::run_all<T>(run_list);
  }
};

}  // namespace details

}  // namespace she_test

#define SHE_TEST(test_suite_name, test_name)                                                 \
  namespace test_suite_name {                                                                \
  bool test_name();                                                                          \
  struct test_name##_register {                                                              \
    test_name##_register() {                                                                 \
      she_test::details::register_center<>::add_test(#test_suite_name, #test_name, test_name); \
    }                                                                                        \
  } test_name##_instance;                                                                    \
  }                                                                                          \
  bool test_suite_name::test_name()

#endif  // SHE_TEST_REGISTER_CENTER_H
