//
// Created by shecannotsee on 24-5-6.
//

#ifndef COMMAND_LINE_PARSE_TEST_MAIN_H
#define COMMAND_LINE_PARSE_TEST_MAIN_H

#include <iostream>

#include "../test_support.h"
#include "command_line/options.h"
#include "command_line/parser.h"
#include "she_test.h"

namespace command_line_parse_test {

inline void exec(const std::vector<she_test::details::parame_packages>& ops) {
  using namespace she_test;

  for (const auto& e : ops) {
    switch (e.key) {
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
        for (const auto& test_cases : e.value) {
          try {
            auto ret = parser::split_suite_name_and_test_case(test_cases);
            std::cout << "suite name:" << std::get<0>(ret) << ",";
            std::cout << "test case name:" << std::get<1>(ret) << std::endl;
          } catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
          }
        }
        break;
      }
      case details::options::EXCLUDE_SOME_TESTS: {
        std::cout << "exclude:\n";
        for (const auto& test_cases : e.value) {
          try {
            auto ret = parser::split_suite_name_and_test_case(test_cases);
            std::cout << "suite name:" << std::get<0>(ret) << ",";
            std::cout << "test case name:" << std::get<1>(ret) << std::endl;
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
        for (const auto& error_options : e.value) {
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

inline int run_test() {
  test_support _("command_line_parse_test");
  /* version */ {
    constexpr int argc = 2;
    const char* argv[]{"she_test_test", "-version"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* help */ {
    constexpr int argc = 2;
    const char* argv[]{"she_test_test", "-help"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* list */ {
    constexpr int argc = 2;
    const char* argv[]{"she_test_test", "-list"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* list */ {
    constexpr int argc = 4;
    const char* argv[]{"she_test_test", "-run", "s1.t1", "s1.t2"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* run */ {
    constexpr int argc = 5;
    const char* argv[]{"she_test_test", "-exclude", "s1.t1", "s2.t1", "s3,t1"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* run all */ {
    constexpr int argc = 1;
    const char* argv[]{"she_test_test"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }
  /* error test */ {
    constexpr int argc = 2;
    const char* argv[2]{"she_test_test", "hahahah"};
    she_test::parser::get_instance().parse(argc, const_cast<char**>(argv));
    exec(she_test::parser::get_instance().get_ops());
  }

  return 0;
}
}  // namespace command_line_parse_test

#endif  // COMMAND_LINE_PARSE_TEST_MAIN_H
