#include <she_test.h>

#include <iostream>

TEST(level, test) {
  std::cout << "level test" << std::endl;
}

TEST1(test1) {
}

TEST2(level1, test) {
}

TEST3(level1, level2, test) {
}

TEST4(level1, level2, level3, test) {
}

TEST5(level1, level2, level3, level4, test) {
}

TEST6(level1, level2, level3, level4, level5, test) {
}

TEST7(level1, level2, level3, level4, level5, level7, test) {
}