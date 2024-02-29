//
// Created by shecannotsee on 24-2-29.
//
#include <she_test.h>

// SHE_TEST(zzz, xxx) {
//   std::cout << "hahahahah\n";
//   return true;
// }

// This macro is equivalent to the following code

namespace zzz {
bool xxx();

struct xxx_register {
  xxx_register() {
    she_test::details::register_center::add_test("zzz", "xxx", xxx);
  }
} xxx_instance;
}  // namespace zzz

bool zzz::xxx() {
  return false;
}
