### 简介

she_test 是一个cpp的测试框架

作者：shecannotsee（shecannotsee@163.com）



### 特点

- she_test 具有强大的表达能力，能够管理多级的测试用例，目前最大支持 17 个层级的测试用例的管理（因为我觉得此数量的层级应该足够满足日常开发和使用了，但是您可以非常容易的提高到更多层级）。
- she_test 是基于 c++17开发。
- she_test 可以让您无需管理测试用例，只需要在测试入口添加简单的代码即可做到全局测试用例的管理。稍后在运行时，您还可以根据输入的参数来运行指定的测试用例。



### 使用说明

#### 1.全局管理

您只需要按照如下方式初始化库即可做到所有的测试用例的管理。

```cpp
/* @file test_main.cpp */
#include <she_test.h>

int main(int argc,char**argv) {
  // 如果您想使用其他的输出方式，需要手动实现并添加实例，框架默认提供了 gtest 和 style_v1 的样式供您选择
  she_test::run_all_test<>(argc, argv);// 等价于下面注释的代码
  // she_test::run_all_test<she_test::format::gtest>(argc, argv);
  // 或者使用 style_v1 的格式进行输出
  // she_test::run_all_test<she_test::format::style_v1>(argc, argv);
  return 0;
}
```



#### 2.测试用例编写

接下来您需要添加您的测试用例。这里总共添加了两个测试套件suite1（包含3个测试用例）和suite2（包含4个测试用例），总共7个测试用例。

```cpp
/* @file suite1.cpp */
#include <she_test.h>
TEST(suite1, case1) {
    // ......
}

TEST(suite1, case2) {
	// ......
}

TEST(suite1, case3) {
	// ......
}

/* @file suite2.cpp */
#include <she_test.h>
TEST(suite2, case1) {
	// ......
}

TEST(suite2, case2) {
	// ......
}

TEST(suite2, case3) {
	// ......
}

TEST(suite2, case_4) {
	// ......
}
```

当然，由于添加了更强大的层级管理，您可以按照以下方式来添加更多的测试用例

```c++
#include <she_test.h>

TEST1(test1){
    // ......
}

TEST2(test1, test2){
    // ......
}

TEST3(test1, test2, test3){
    // ......
}

TEST4(test1, test2, test3, test4){
    // ......
}

// ......
// 不修改源代码的情况下支持的最大层级就是 17 级，若要提高层级，参考 she_test/src/test_case_registry/multi_level_test_case.h 中的宏编写规律，自定义添加即可
TEST17(test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16, test17) {
    // ......
}
```



#### 3.使用命令行控制运行的测试用例

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

# 运行三个测试用例（suite1.case1 、suite1.case2 、suite2.case4）
./program_test -run suite1.case1 suite1.case2 suite2.case4

# 运行三个测试用例（suite1.case1 、suite1.case2 、suite2.case4）然后剔除一个测试用例（suite2.case_false）
./program_test -run suite1.case1 suite1.case2 suite2.case4 -exclude suite2.case_false

# 运行所有测试用例，但是剔除一个测试用例（suite2.case4）
./program_test -run_all -exclude suite2.case4
```



### 获取源码以及构建项目

```bash
$ git clone https://github.com/shecannotsee/she_test
$ cd she_test
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=./ \
  -Dbuild_release=ON \
  -Dbuild_tests=OFF \
  -Dbuild_shared_libs=ON \
  ..
$ make -j8
$ make install
$ tree tree
.
├── include
│   ├── command_line
│   │   ├── options.h
│   │   └── parser.h
│   ├── format
│   │   ├── color.h
│   │   ├── fmt.h
│   │   ├── gtest.h
│   │   ├── style_v1.h
│   │   └── template_format.h
│   ├── run_all_test.h
│   ├── she_test.h
│   ├── test_case_registry
│   │   └── multi_level_test_case.h
│   └── test_tools
│       └── equal.h
└── lib
    ├── libshe_test.a
    └── libshe_test.so

6 directories, 13 files
$
```

