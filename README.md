### Introduction

she_test is a C++ testing framework.

Author: shecannotsee (shecannotsee@163.com)

### Features

- she_test is header-only, you only need to add the files in the src directory to your code to use it.
- she_test is developed based on C++11.
- she_test allows you to manage test cases globally without the need to manage them manually. You only need to add simple code at the test entry point. Later at runtime, you can also run specific test cases based on input parameters.

### Usage

Simply initialize the library as follows to manage all your test cases:

```cpp
/* @file test_main.cpp */
#include <she_test.h>

int main(int argc, char** argv) {
    // If you want to use other output methods, you need to manually implement and add instances
    she_test::details::register_center<>::init_and_run(argc, argv);
    return 0;
}
```

Next, you need to add your test cases. Here, two test suites suite1 (containing 3 test cases) and suite2 (containing 4 test cases) are added, totaling 7 test cases.

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

After compiling, you can use parameters to control the execution of test cases (here program_test is used to represent the executable file).

```cpp
# View the version of the testing framework
./program_test -version

# View the help information of the testing framework
./program_test -help

# Run all test cases
./program_test
./program_test -run_all

# List all test cases
./program_test -list

# Run three test cases (suite1.case1, suite1.case2, suite2.case_false)
./program_test -run suite1.case1 suite1.case2 suite2.case_false

# Run three test cases (suite1.case1, suite1.case2, suite2.case_false) and then exclude one test case (suite2.case_false)
./program_test -run suite1.case1 suite1.case2 suite2.case_false -exclude suite2.case_false

# Run all test cases but exclude one test case (suite2.case_false)
./program_test -run_all -exclude suite2.case_false
```

### Getting the Source Code and Building the Project

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
│   └── she_test_test
└── include
    ├── command_line_parser
    │   ├── command_line.h
    │   └── options.h
    ├── output_format
    │   ├── common.h
    │   ├── gtest_format.h
    │   └── she_test_v1.h
    ├── print_color.h
    ├── she_test.h
    ├── template_support
    │   └── equal.h
    └── test_case_registry
        ├── register_center.h
        └── test_case.h

6 directories, 11 files
$
```
