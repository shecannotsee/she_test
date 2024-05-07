### 简介

she_test 是一个cpp的测试框架

作者：shecannotsee（shecannotsee@163.com）



### 特点

- she_test 是 header-only 的，您只需要把 src 里的文件添加到您的代码中即可使用。
- she_test 是基于 c++11开发。
- she_test 可以让您无需管理测试用例，只需要在测试入口添加简单的代码即可做到全局测试用例的管理。稍后在运行时，您还可以根据输入的参数来运行指定的测试用例。



### 使用说明

您只需要按照如下方式初始化库即可做到所有的测试用例的管理。

```cpp
/* @file test_main.cpp */
#include <she_test.h>

int main(int argc,char**argv) {
    // 如果您想使用其他的输出方式，需要手动实现并添加实例
    she_test::details::register_center<>::init_and_run(argc, argv);
    return 0;
}
```

接下来您需要添加您的测试用例。这里总共添加了两个测试套件suite1（包含3个测试用例）和suite2（包含4个测试用例），总共7个测试用例。

```cpp
/* @file suite1.cpp */
#include <she_test.h>
SHE_TEST(suite1, case1) {
    // ......
    return true;
}

SHE_TEST(suite1, case2) {
    // ......
    return true;
}

SHE_TEST(suite1, case3) {
    // ......
  	return true;
}

/* @file suite2.cpp */
#include <she_test.h>
SHE_TEST(suite2, case1) {
  return true;
}

SHE_TEST(suite2, case2) {
  return true;
}

SHE_TEST(suite2, case3) {
  return true;
}

SHE_TEST(suite2, case_false) {
  return false;
}
```

在编译后可以使用参数来控制测试用例的运行（这里用 program_test 来代表可执行文件）

```bash
# 查看测试框架版本
./program_test -version

# 查看测试框架帮助信息
./program_test -help

# 运行所有测试用例
./program_test
./program_test -run_all

# 查看所有测试用例
./program_test -list

# 运行三个测试用例（suite1.case1 、suite1.case2 、suite2.case_false）
./program_test -run suite1.case1 suite1.case2 suite2.case_false

# 运行三个测试用例（suite1.case1 、suite1.case2 、suite2.case_false）然后剔除一个测试用例（suite2.case_false）
./program_test -run suite1.case1 suite1.case2 suite2.case_false -exclude suite2.case_false

# 运行所有测试用例但是剔除一个测试用例（suite2.case_false）
./program_test -run_all -exclude suite2.case_false
```



### 获取源码以及构建项目

```bash
$ git clone https://github.com/shecannotsee/she_test
$ cd she_test
$ mkdir build
$ cd build
$ cmake ..
$ make -j8
$ make install
$ tree she_test
she_test
├── bin
│   └── she_test_test
└── include
    ├── command_line_parser
    │   ├── command_line.h
    │   └── options.h
    ├── output_format
    │   ├── common.h
    │   ├── gtest_format.h
    │   └── she_test_v1.h
    ├── print_color.h
    ├── she_test.h
    ├── template_support
    │   └── equal.h
    └── test_case_registry
        ├── register_center.h
        └── test_case.h

6 directories, 11 files
$
```

