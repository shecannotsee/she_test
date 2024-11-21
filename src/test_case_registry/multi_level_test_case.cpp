#include "multi_level_test_case.h"

#include <stdexcept>

auto multi_level_test_case::test_case_name_to_string(const test_case_name& names) -> std::string {
  std::string string;
  for (const auto& name : names) {
    string += name;
  }
  return string;
}

auto multi_level_test_case::get_instance() -> multi_level_test_case& {
  static multi_level_test_case instance;
  return instance;
}

void multi_level_test_case::add(const std::vector<std::string>& name, const test_case_func& func) {
  const std::string key = test_case_name_to_string(name);
  test_case_table_[key] = func;
  test_case_list_.emplace_back(name);
}

void multi_level_test_case::run(const test_case_name& name, bool& pass) {
  const auto key = test_case_name_to_string(name);
  // Not found
  if (const auto it = test_case_table_.find(key); it == test_case_table_.end()) {
    throw std::runtime_error("test_case_name not found");
  }
  const auto func = test_case_table_.at(key);
  // run
  func(pass);
}
