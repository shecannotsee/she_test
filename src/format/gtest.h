#ifndef SHE_TEST_FORMAT_GTEST_H
#define SHE_TEST_FORMAT_GTEST_H

#include <vector>

#include "template_format.h"

namespace she_test::format {

class gtest final : public template_format {
  uint64_t test_number_;
  std::vector<std::string> test_list_;

 public:
  explicit gtest(uint64_t test_number, const std::vector<std::string>& test_list);

  ~gtest() override;

  void global_start() override;

  void global_end() override;

  void before_test_case(const std::string& test_name) override;

  void after_test_case(const std::string& test_name) override;
};

}  // namespace she_test::format

#endif  // SHE_TEST_FORMAT_GTEST_H
