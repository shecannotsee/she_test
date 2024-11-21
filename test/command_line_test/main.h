#ifndef TEST_COMMAND_LINE_TEST_MAIN_H
#define TEST_COMMAND_LINE_TEST_MAIN_H

#include <iostream>

#include "../test_support.h"

namespace command_line_test {

inline void exec(const std::vector<she_test::details::parameter_pack>& ops) {
  using namespace she_test;

  for (const auto& [key, value] : ops) {
    switch (key) {
      case details::options::VERSION: {
        std::cout << "she_test version " << version << std::endl;
        break;
      }
      case details::options::HELP: {
        std::cout << details::help_message << std::endl;
        break;
      }
      case details::options::LIST_ALL_TESTS: {
        std::cout << "list all test cases\n";
        break;
      }
      case details::options::RUN_SOME_TESTS: {
        std::cout << "run:\n";
        for (const auto& test_cases : value) {
          try {
            auto test_case_name = command_line::split_test_case_name(test_cases);
            // show
            for (const auto& name : test_case_name) {
              std::cout << name << " ";
            }
          } catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
          }
        }
        break;
      }
      case details::options::EXCLUDE_SOME_TESTS: {
        std::cout << "exclude:\n";
        for (const auto& test_cases : value) {
          try {
            auto test_case_name = command_line::split_test_case_name(test_cases);
            for (const auto& name : test_case_name) {
              std::cout << name << " ";
            }
          } catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
          }
        }
        break;
      }
      case details::options::RUN_ALL_TESTS: {
        std::cout << "run all test:\n";
        break;
      }
      case details::options::UNKNOWN: {
        std::cout << "error options:\n";
        for (const auto& error_options : value) {
          std::cout << error_options << std::endl;
        }
        break;
      }
      default: {
        break;
      }
    }  // switch
  }
}

inline void run_test() {
  test_support _("command_line_parse_test");
  /* version */ {
    constexpr int argc = 2;
    const char* argv[argc]{"she_test_test", "-version"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* help */ {
    constexpr int argc = 2;
    const char* argv[argc]{"she_test_test", "-help"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* list */ {
    constexpr int argc = 2;
    const char* argv[argc]{"she_test_test", "-list"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* list */ {
    constexpr int argc = 5;
    const char* argv[argc]{"she_test_test", "-run", "l1.t1", "l1.t2", "l1.l2.t1"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* run */ {
    constexpr int argc = 6;
    const char* argv[argc]{"she_test_test", "-exclude", "l1.t1", "l2.t1", "l3.t1", "l1.l2.l3.l4.l5.l6.l7.l8.l9.t1"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* run all */ {
    constexpr int argc = 1;
    const char* argv[argc]{"she_test_test"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* error test */ {
    constexpr int argc = 2;
    const char* argv[argc]{"she_test_test", "error"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
  /* error test */ {
    constexpr int argc = 3;
    const char* argv[argc]{"she_test_test", "-run", "asdad,dsad"};
    const auto ops = she_test::command_line::parse(argc, const_cast<char**>(argv));
    exec(ops);
  }
}
}  // namespace command_line_test

#endif  // TEST_COMMAND_LINE_TEST_MAIN_H
