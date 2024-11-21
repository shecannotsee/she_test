#ifndef SHE_TEST_FORMAT_TEMPLATE_FORMAT_H
#define SHE_TEST_FORMAT_TEMPLATE_FORMAT_H

#include <chrono>
#include <cstdint>
#include <string>

namespace she_test::format {

class template_format {
  uint64_t total_number_of_tests;
  uint64_t failed_tests;
  uint64_t test_time;
  std::chrono::high_resolution_clock::time_point start_time;

 public:
  template_format()
      : total_number_of_tests(0), failed_tests(0), test_time(0), start_time(std::chrono::high_resolution_clock::now()) {
  }
  virtual ~template_format() = default;

  [[nodiscard]] auto get_test_number() const -> uint64_t {
    return total_number_of_tests;
  }
  void set_test_number(const uint64_t test_number) {
    total_number_of_tests = test_number;
  }
  [[nodiscard]] auto get_failed_tests() const -> uint64_t {
    return failed_tests;
  }
  void add_failed_test_number() {
    failed_tests++;
  }
  void start_test_time() {
    start_time = std::chrono::high_resolution_clock::now();
  }
  auto end_test_time() -> uint64_t {
    const auto end_time = std::chrono::high_resolution_clock::now();
    const auto elapsed  = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    test_time += elapsed.count();
    return elapsed.count();
  }
  [[nodiscard]] auto get_test_time() const -> uint64_t {
    return test_time;
  }

  virtual void global_start() = 0;
  virtual void global_end()   = 0;

  virtual void before_test_case(const std::string& test_name)                  = 0;
  virtual void after_test_case(const std::string& test_name, bool& pass) = 0;
};

}  // namespace she_test::format

#endif  // SHE_TEST_FORMAT_TEMPLATE_FORMAT_H
