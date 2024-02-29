//
// Created by shecannotsee on 24-2-29.
//
#include <she_test.h>

bool lalala_dididi();

namespace {
struct lalala_dididi_test {
  lalala_dididi_test() {
    she_test::test_case_manager::add("lalala", "dididi", lalala_dididi);
  }
} lalala_dididi_test_;

}  // namespace

bool lalala_dididi() {
  std::cout << "lalala_dididi";
  return true;
}
