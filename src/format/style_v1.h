#ifndef SHE_TEST_S_TEST_V1_H
#define SHE_TEST_S_TEST_V1_H

#include "template_format.h"

namespace she_test::format {

class style_v1 : public template_format {
 public:
  explicit style_v1(const std::vector<std::tuple<std::string, std::string>>& list);

  ~style_v1() override;

  void NO_TEST_SUITE(const std::string& suite_name) noexcept override;

  void NO_TEST_CASE(const std::string& suite_name, const std::string& test_name) noexcept override;

  void READY_TO_RACE(const std::string& test_suite_name,
                     const std::string& test_name,
                     const details::test_function& waiting_to_run) noexcept override;
};

}  // namespace she_test::format

#endif  // SHE_TEST_S_TEST_V1_H
