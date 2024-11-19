#ifndef SHE_TEST_OPERATION_H
#define SHE_TEST_OPERATION_H

#include <string>
#include <unordered_map>

namespace she_test {

namespace details {
enum class options : int {
  VERSION = 0,
  HELP,
  LIST_ALL_TESTS,
  RUN_SOME_TESTS,
  EXCLUDE_SOME_TESTS,
  RUN_ALL_TESTS,  // default
  UNKNOW          // default
};

static std::unordered_map<options, std::string> options_desc = {
    std::make_pair(options::VERSION, "Get version"),
    std::make_pair(options::HELP, "You may need some help"),
    std::make_pair(options::LIST_ALL_TESTS, "Get all test cases"),
    std::make_pair(options::RUN_SOME_TESTS, "Run some tests"),
    std::make_pair(options::EXCLUDE_SOME_TESTS, "Exclude some test cases"),
    std::make_pair(options::RUN_ALL_TESTS, "Default: run all test cases"),
    std::make_pair(options::UNKNOW, "Default: unknow"),
};

static std::unordered_map<std::string, options> options_table = {
    std::make_pair("-version", options::VERSION),
    std::make_pair("-help", options::HELP),
    std::make_pair("-list", options::LIST_ALL_TESTS),
    std::make_pair("-run", options::RUN_SOME_TESTS),
    std::make_pair("-exclude", options::EXCLUDE_SOME_TESTS),
    std::make_pair("-run_all", options::RUN_ALL_TESTS),
};

constexpr int major = 0;
constexpr int minor = 0;
constexpr int patch = 1;
const std::string version = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);

static std::string help_message{
  ""
  "-version               Get version\n"
  "-help                  You may need some help\n"
  "-list                  Get all test cases\n"
  "-run                   Run some tests\n"
  "-exclude               Exclude some test cases\n"
  "-run_all               Run all tests\n"
  "                       Default: run all test cases\n"
  "\n "};

}  // namespace details

}  // namespace she_test

#endif  // SHE_TEST_OPERATION_H
