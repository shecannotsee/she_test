#ifndef SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
#define SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H

#include <functional>
#include <string>

class multi_level_test_case {
  using function_type = std::function<void()>;
  std::unordered_map<std::string, function_type> function_table_;
  std::vector<std::vector<std::string>> function_names_;

  register_demo() = default;

  static auto get_instance() -> multi_level_test_case {
    static multi_level_test_case instance;
    return instance;
  }

  void insert(const std::vector<std::string>& names, const function_type& func) {
    std::string key;
    for (const auto& name : names) {
      key += name;
    }
    function_table_[key] = func;
    function_names_.emplace_back(names);
  }

  auto find(const std::vector<std::string>& names) const -> function_type {
    std::string key;
    for (const auto& name : names) {
      key += name;
    }
    // Not found
    if (const auto it = function_table_.find(key); it == function_table_.end()) {
      return nullptr;
    }
    // Return function
    return function_table_.at(key);
  }

  void run_all_recursive() {
    for (const auto& function_name : function_names_) {
      std::string key;
      for (const auto& name : function_name) {
        key += name;
      }
      const auto func = function_table_[key];
      if (func != nullptr) {
        func();
      }
    }
  }

 public:
  static void add(const std::vector<std::string>& names, const function_type& func) {
    get_instance().insert(names, func);
  }

  static auto get_all() {
  }

  template <typename output_format_type>
  static void run_all(const std::vector<std::string>& names);

 private:
  template <typename output_format_type>
  static void run(const std::vector<std::string>& names, output_format_type&& format);
};

#include "multi_level_test_case_impl.h"

#endif  // SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
