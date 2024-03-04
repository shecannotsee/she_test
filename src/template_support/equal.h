//
// Created by shecannotsee on 24-3-4.
//

#ifndef SHE_TEST_EQUAL_H
#define SHE_TEST_EQUAL_H

#include <iostream>
#include <type_traits>

namespace she_test {

#if __cplusplus >= 201703L  // standard >= c++17

template <typename T, typename... Args>
bool check_equal(const T& first, const Args&... args) {
  static_assert(sizeof...(Args) >= 1, "At least two arguments required.");
  return ((first == args) && ...);  // check
}

#elif __cplusplus >= 201103L  // standard >= c++11 && standard < c++17

template <typename T>
bool check_equal(const T& first) {
  static_assert(sizeof(T) != sizeof(T), "At least two arguments required.");
  return false;
}

template <typename T>
bool check_equal(const T& first, const T& second) {
  return first == second;  // 检查两个值是否相等
}

template <typename T, typename... Args>
bool check_equal(const T& first, const T& second, const Args&... args) {
  return first == second && check_equal(first, args...);  //
}

#endif

}  // namespace she_test

#endif  // SHE_TEST_EQUAL_H
