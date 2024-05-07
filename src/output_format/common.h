#ifndef OUTPUT_FORMAT_COMMON_H
#define OUTPUT_FORMAT_COMMON_H

#include <stdio.h>

#include "../print_color.h"
#include "test_case_registry/test_case.h"

namespace she_test {

namespace output_format {

namespace common {

using namespace print_color;

static void colorful(const std::string& str1, const char* color = RESET_COLOR) {
  printf("%s%s%s", color, str1.c_str(), RESET_COLOR);
}
static void colorful(const std::string& str1, const std::string& str2, const char* color = RESET_COLOR) {
  printf("%s%s%s%s", color, str1.c_str(), RESET_COLOR, str2.c_str());
}
static void colorful_ln(const std::string& str, const char* color = RESET_COLOR) {
  printf("%s%s%s\n", color, str.c_str(), RESET_COLOR);
}
static void colorful_ln(const std::string& str, const std::string& str2, const char* color = RESET_COLOR) {
  printf("%s%s%s%s\n", color, str.c_str(), RESET_COLOR, str2.c_str());
}

template <typename integer_type = int>
struct test_info {
  static_assert(std::is_integral<integer_type>::value, "integer_type must be an integral type");

  integer_type total_number_of_tests{0};
  integer_type failed_tests{0};
  integer_type total_number_of_suites{0};
  integer_type total_time{0};
  std::string module_name{};
  explicit test_info(const std::vector<std::tuple<std::string, std::string>>& list) {
    /* Get suite snumber */
    {
      std::unordered_map<std::string, int> unique_elements;
      for (const auto& tuple : list) {
        const std::string& element = std::get<0>(tuple);
        unique_elements[element]++;
      }
      for (const auto& pair : unique_elements) {
        module_name += pair.first + "(" + std::to_string(pair.second) + ") ";
        ++total_number_of_suites;
      }
    }
    /* Get test case number */
    total_number_of_tests = list.size();
  }
  virtual ~test_info() = default;

  // I love KTM-R2R!
  virtual void READY_TO_RACE(const std::string&, const std::string&, const details::test_function&) noexcept = 0;

  virtual void NO_TEST_SUITE(const std::string& suite_name) noexcept = 0;

  virtual void NO_TEST_CASE(const std::string& suite_name, const std::string& test_name) noexcept = 0;

  /*
   * @return return millseconds
   */
  virtual int run_and_check(const details::test_function& waiting_to_run) {
    if (waiting_to_run) {
      const auto start = std::chrono::high_resolution_clock::now();
      if (!waiting_to_run()) {
        ++failed_tests;
      }
      const auto end      = std::chrono::high_resolution_clock::now();
      const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      return duration.count();
    }
    return 0;
  }
};

}  // namespace common

}  // namespace output_format

}  // namespace she_test

#endif  // OUTPUT_FORMAT_COMMON_H
