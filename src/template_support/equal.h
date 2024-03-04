//
// Created by shecannotsee on 24-3-4.
//

#ifndef SHE_TEST_EQUAL_H
#define SHE_TEST_EQUAL_H

#include <iostream>

namespace she_test {

#if __cplusplus >= 201703L  // standard >= c++17

template <typename T, typename... Args>
bool check_equal(T&& first, Args&&... args) {
  static_assert(sizeof...(Args) >= 1, "At least two arguments required.");
  return ((first == args) && ...);  // check
}

#elif __cplusplus >= 201103L  // standard >= c++11 && standard < c++17

template <typename T>
bool check_equal(T&& first) {
  static_assert(sizeof(T) != sizeof(T), "At least two arguments required.");
  return false;
}

template <typename T>
bool check_equal(T&& first, T&& second) {
  return first == second;  // check
}

template <typename T, typename... Args>
bool check_equal(T&& first, T&& second, Args&&... args) {
  return first == second && check_equal(first, args...);  //
}

#endif

#define CHECK_EQUAL(...)                                              \
  {                                                                   \
    if (!she_test::check_equal<decltype(__VA_ARGS__)>(__VA_ARGS__)) { \
      printf("%s:%d\n", __FILE__, __LINE__);                          \
    }                                                                 \
  }

}  // namespace she_test

#endif  // SHE_TEST_EQUAL_H
