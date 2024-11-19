#ifndef SHE_TEST_FORMAT_TEMPLATE_FORMAT_H
#define SHE_TEST_FORMAT_TEMPLATE_FORMAT_H

#include <chrono>

#include "test_case_registry/test_case.h"

namespace she_test::format {

class template_format {
 public:
  int total_number_of_tests;
  int failed_tests;
  int total_number_of_suites;
  int total_time;
  std::string module_name;


  explicit template_format(const std::vector<std::tuple<std::string, std::string>>& list);

  virtual ~template_format() = default;

  // I love KTM-R2R!
  virtual void READY_TO_RACE(const std::string&, const std::string&, const details::test_function&) noexcept = 0;

  virtual void NO_TEST_SUITE(const std::string& suite_name) noexcept = 0;

  virtual void NO_TEST_CASE(const std::string& suite_name, const std::string& test_name) noexcept = 0;

  /*
   * @return return millseconds
   */
  virtual int run_and_check(const details::test_function& waiting_to_run);
};

}  // namespace she_test::format

#endif  // SHE_TEST_FORMAT_TEMPLATE_FORMAT_H
