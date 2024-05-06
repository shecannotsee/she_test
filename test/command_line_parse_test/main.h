//
// Created by shecannotsee on 24-5-6.
//

#ifndef COMMAND_LINE_PARSE_TEST_MAIN_H
#define COMMAND_LINE_PARSE_TEST_MAIN_H

#include "../test_support.h"
#include "command_line_parser/help.h"
#include "command_line_parser/version.h"

namespace command_line_parse_test {

void exec(std::vector<she_test::details::parame_packages> ops) {
  using namespace she_test;

  for (const auto& e : ops) {
    switch (e.key) {
      case options::VERSION: {
        std::cout << "she_test version " << details::version << std::endl;
        break;
      }
      case options::HELP: {
        std::cout << details::help_message << std::endl;
        break;
      }
      case options::LIST_ALL_TESTS: {
        std::cout << "list all test cases\n";
        break;
      }
      case options::RUN_SOME_TESTS: {
        std::cout << "run:\n";
        for (const auto& test_cases : e.value) {
          try {
            auto ret = command_line::split_suite_name_and_test_case(test_cases);
            std::cout << "suite name:" << std::get<0>(ret) << ",";
            std::cout << "test case name:" << std::get<1>(ret) << std::endl;
          } catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
          }
        }
        break;
      }
      case options::EXCLUDE_SOME_TESTS: {
        std::cout << "exclude:\n";
        for (const auto& test_cases : e.value) {
          try {
            auto ret = command_line::split_suite_name_and_test_case(test_cases);
            std::cout << "suite name:" << std::get<0>(ret) << ",";
            std::cout << "test case name:" << std::get<1>(ret) << std::endl;
          } catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
          }
        }
        break;
      }
      case options::RUN_ALL_TESTS: {
        std::cout << "run all test:\n";
        break;
      }
      case options::UNKNOW: {
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
    int argc = 2;
    char* argv[]{"she_test_test", "-version"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* help */ {
    int argc = 2;
    char* argv[]{"she_test_test", "-help"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* list */ {
    int argc = 2;
    char* argv[]{"she_test_test", "-list"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* list */ {
    int argc = 4;
    char* argv[]{"she_test_test", "-run", "s1.t1", "s1.t2"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* run */ {
    int argc = 5;
    char* argv[]{"she_test_test", "-exclude", "s1.t1", "s2.t1","s3,t1"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* run all */ {
    int argc = 1;
    char* argv[]{"she_test_test"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }
  /* error test */ {
    int argc = 2;
    char* argv[]{"she_test_test", "hahahah"};
    she_test::command_line::getInstance().parse(argc, argv);
    exec(she_test::command_line::getInstance().get_ops());
  }

  return 0;
}
}  // namespace command_line_parse_test

#endif  // COMMAND_LINE_PARSE_TEST_MAIN_H
