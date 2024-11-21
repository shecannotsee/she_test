#include <she_test.h>

#include <iostream>

TEST(level, test) {
  std::cout << "level/test" << std::endl;
}

TEST1(test1) {
  std::cout << "/test" << std::endl;
}

TEST2(level1, test) {
  std::cout << "/level1/test" << std::endl;
}

TEST3(level1, level2, test) {
  std::cout << "/level1/level2/test" << std::endl;
}

TEST4(level1, level2, level3, test) {
  std::cout << "/level1/level2/level3/test" << std::endl;
}

TEST5(level1, level2, level3, level4, test) {
  std::cout << "/level1/level2/level3/level4/test" << std::endl;
}

TEST6(level1, level2, level3, level4, level5, test) {
  std::cout << "/level1/level2/level3/level4/level5/test" << std::endl;
}

TEST7(level1, level2, level3, level4, level5, level6, test) {
  std::cout << "/level1/level2/level3/level4/level/level6/test" << std::endl;
}