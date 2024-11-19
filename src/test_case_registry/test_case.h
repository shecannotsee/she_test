#ifndef SHE_TEST_TEST_CASE_H
#define SHE_TEST_TEST_CASE_H

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace she_test {

namespace details {
using namespace std;
using test_function    = function<bool()>;
using test_suite_table = unordered_map<string, unordered_map<string, test_function>>;
}  // namespace details

class test_case {
  static auto get_instance() -> test_case&;

  details::test_suite_table tests_;

 public:
  static void add(const std::string& suite_name,
                  const std::string& test_name,
                  const details::test_function& test_func = nullptr);

  static auto get_all() -> std::vector<std::tuple<std::string, std::string>>;

  template <typename output_format_type>
  static void run_all(const std::vector<std::tuple<std::string, std::string>>& list);

 private:
  template <typename output_format_type>
  static void run(const std::string& suite_name, const std::string& test_name, output_format_type&& format);
};
}  // namespace she_test

#include "test_case_impl.h"

#endif  // SHE_TEST_TEST_CASE_H
