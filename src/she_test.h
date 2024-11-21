#ifndef SHE_TEST_H
#define SHE_TEST_H

#include "run_all_test.h"
#include "test_case_registry/multi_level_test_case.h"

namespace she_test {
constexpr int major       = 0;
constexpr int minor       = 0;
constexpr int patch       = 1;
const std::string version = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}  // namespace she_test

#endif  // SHE_TEST_H
