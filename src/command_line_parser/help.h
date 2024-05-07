#ifndef SHE_TEST_HELP_H
#define SHE_TEST_HELP_H

#include <string>

namespace she_test {

namespace details {

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

#endif  // SHE_TEST_HELP_H
