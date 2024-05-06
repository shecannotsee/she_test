#ifndef SHE_TEST_VERSION_H
#define SHE_TEST_VERSION_H

#include <string>

namespace she_test {

namespace details {

constexpr int major = 0;
constexpr int minor = 0;
constexpr int patch = 1;

const std::string version = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);

}  // namespace details

}  // namespace she_test

#endif  // SHE_TEST_VERSION_H
