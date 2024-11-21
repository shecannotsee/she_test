### Introduction

**she_test** is a C++ testing framework.

**Author**: shecannotsee (shecannotsee@163.com)



### Features

- **she_test** is highly expressive and supports multi-level test case management, accommodating up to 17 levels by default. This is designed to meet most development needs, but you can easily extend it to support more levels if required.
- It is developed using **C++17**.
- **she_test** simplifies test case management. You only need to add minimal code at the test entry point to globally manage test cases. At runtime, you can execute specific test cases using input parameters.



### Usage Guide

#### 1. Global Management

You can manage all test cases by initializing the library as shown below:

```cpp
/* @file test_main.cpp */
#include <she_test.h>

int main(int argc, char** argv) {
  // To use other output formats, you need to implement and add a custom instance.
  // By default, the framework provides `gtest` and `style_v1` styles for selection.
  she_test::run_all_test<>(argc, argv); // Equivalent to the commented code below
  // she_test::run_all_test<she_test::format::gtest>(argc, argv);
  // Or use the `style_v1` format for output
  // she_test::run_all_test<she_test::format::style_v1>(argc, argv);
  return 0;
}

```



#### 2. Writing Test Cases

Next, add your test cases. Below, two test suites (`suite1` and `suite2`) are defined. `suite1` contains three test cases, and `suite2` contains four, for a total of seven test cases.

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

With the enhanced hierarchical management, you can add more test cases as follows:

```c++
#include <she_test.h>

TEST1(test1) {
    // ......
}

TEST2(test1, test2) {
    // ......
}

TEST3(test1, test2, test3) {
    // ......
}

TEST4(test1, test2, test3, test4) {
    // ......
}

// ......
// The maximum supported level is 17 by default without modifying the source code.
// To increase this limit, refer to the macro patterns in 
// she_test/src/test_case_registry/multi_level_test_case.h and customize accordingly.
TEST17(test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16, test17) {
    // ......
}

```



#### 3. Controlling Test Execution with Command-Line Arguments

After compiling the project, use the following commands to control the test execution (assuming the executable is `program_test`):

```bash
# View the framework version
./program_test -version

# View the help information
./program_test -help

# Run all test cases
./program_test
./program_test -run_all

# List all test cases
./program_test -list

# Run three test cases (suite1.case1, suite1.case2, suite2.case4)
./program_test -run suite1.case1 suite1.case2 suite2.case4

# Run three test cases (suite1.case1, suite1.case2, suite2.case4) and exclude one (suite2.case_false)
./program_test -run suite1.case1 suite1.case2 suite2.case4 -exclude suite2.case_false

# Run all test cases except one (suite2.case4)
./program_test -run_all -exclude suite2.case4
```



### Source Code and Project Build

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

