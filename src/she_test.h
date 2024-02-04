//
// Created by shecannotsee on 24-2-4.
//

#ifndef SHE_TEST_H
#define SHE_TEST_H

#include <utility>

namespace she_test {

// 普通的函数模板
template <typename Func, typename... Args>
void runFunction(Func func, Args&&... args) {
  // 运行函数
  func(std::forward<Args>(args)...);
}

// 部分特化，当标志为true时运行函数
template <typename Func, typename... Args>
void runFunction(Func func, bool flag, Args&&... args) {
  if (flag) {
    // 运行函数
    func(std::forward<Args>(args)...);
  }
}

}

#endif //SHE_TEST_H
