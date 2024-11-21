#ifndef SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
#define SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H

#include <functional>
#include <string>

class multi_level_test_case {
  using test_case_name = std::vector<std::string>;
  static auto test_case_name_to_string(const test_case_name& names) -> std::string;

  using test_case_func = std::function<void(bool&)>;
  std::unordered_map<std::string, test_case_func> test_case_table_;
  std::vector<test_case_name> test_case_list_;

  multi_level_test_case() = default;

  static auto get_instance() -> multi_level_test_case&;

  void add(const test_case_name& name, const test_case_func& func);

  void run(const test_case_name& name, bool& pass);

 public:
  static void add_test_case(const std::vector<std::string>& name, const std::function<void(bool&)>& func) {
    get_instance().add(name, func);
  }

  static auto get_test_case_list() -> std::vector<std::vector<std::string>> {
    std::sort(get_instance().test_case_list_.begin(), get_instance().test_case_list_.end(),
              [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
                if (a.size() != b.size()) {
                  return a.size() < b.size();
                }
                return a < b;
              });
    return get_instance().test_case_list_;
  }

  static void run_test_case(const std::vector<std::string>& test_case_name, bool& pass) {
    get_instance().run(test_case_name, pass);
  }

  static bool test_case_exists(const std::vector<std::string>& test_case_name) {
    const auto table = get_instance().test_case_table_;
    if (const auto it = table.find(test_case_name_to_string(test_case_name)); it == table.end()) {
      return false;
    } else {
      return true;
    }
  }
};

#define TEST(name1, name2)                                            \
  namespace name1::name2 {                                            \
  void __func(bool& __pass);                                          \
  struct __register {                                                 \
    __register() {                                                    \
      multi_level_test_case::add_test_case({#name1, #name2}, __func); \
    }                                                                 \
  } __register_func;                                                  \
  }                                                                   \
  void name1::name2::__func(bool& __pass)

#define TEST1(name1)                                          \
  namespace name1 {                                           \
  void __func(bool& __pass);                                  \
  struct __register {                                         \
    __register() {                                            \
      multi_level_test_case::add_test_case({#name1}, __func); \
    }                                                         \
  } __register_func;                                          \
  }                                                           \
  void name1::__func(bool& __pass)

#define TEST2(name1, name2)                                           \
  namespace name1::name2 {                                            \
  void __func(bool& __pass);                                           \
  struct __register {                                                 \
    __register() {                                                    \
      multi_level_test_case::add_test_case({#name1, #name2}, __func); \
    }                                                                 \
  } __register_func;                                                  \
  }                                                                   \
  void name1::name2::__func(bool& __pass)

#define TEST3(name1, name2, name3)                                            \
  namespace name1::name2::name3 {                                             \
  void __func(bool& __pass);                                                   \
  struct __register {                                                         \
    __register() {                                                            \
      multi_level_test_case::add_test_case({#name1, #name2, #name3}, __func); \
    }                                                                         \
  } __register_func;                                                          \
  }                                                                           \
  void name1::name2::name3::__func(bool& __pass)

#define TEST4(name1, name2, name3, name4)                                             \
  namespace name1::name2::name3::name4 {                                              \
  void __func(bool& __pass);                                                           \
  struct __register {                                                                 \
    __register() {                                                                    \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4}, __func); \
    }                                                                                 \
  } __register_func;                                                                  \
  }                                                                                   \
  void name1::name2::name3::name4::__func(bool& __pass)

#define TEST5(name1, name2, name3, name4, name5)                                              \
  namespace name1::name2::name3::name4::name5 {                                               \
  void __func(bool& __pass);                                                                   \
  struct __register {                                                                         \
    __register() {                                                                            \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5}, __func); \
    }                                                                                         \
  } __register_func;                                                                          \
  }                                                                                           \
  void name1::name2::name3::name4::name5::__func(bool& __pass)

#define TEST6(name1, name2, name3, name4, name5, name6)                                               \
  namespace name1::name2::name3::name4::name5::name6 {                                                \
  void __func(bool& __pass);                                                                           \
  struct __register {                                                                                 \
    __register() {                                                                                    \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6}, __func); \
    }                                                                                                 \
  } __register_func;                                                                                  \
  }                                                                                                   \
  void name1::name2::name3::name4::name5::name6::__func(bool& __pass)

#define TEST7(name1, name2, name3, name4, name5, name6, name7)                                                \
  namespace name1::name2::name3::name4::name5::name6::name7 {                                                 \
  void __func(bool& __pass);                                                                                   \
  struct __register {                                                                                         \
    __register() {                                                                                            \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7}, __func); \
    }                                                                                                         \
  } __register_func;                                                                                          \
  }                                                                                                           \
  void name1::name2::name3::name4::name5::name6::name7::__func(bool& __pass)

#define TEST8(name1, name2, name3, name4, name5, name6, name7, name8)                                                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8 {                                                  \
  void __func(bool& __pass);                                                                                           \
  struct __register {                                                                                                 \
    __register() {                                                                                                    \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8}, __func); \
    }                                                                                                                 \
  } __register_func;                                                                                                  \
  }                                                                                                                   \
  void name1::name2::name3::name4::name5::name6::name7::name8::__func(bool& __pass)

#define TEST9(name1, name2, name3, name4, name5, name6, name7, name8, name9)                                         \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9 {                                          \
  void __func(bool& __pass);                                                                                          \
  struct __register {                                                                                                \
    __register() {                                                                                                   \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9}, \
                                           __func);                                                                  \
    }                                                                                                                \
  } __register_func;                                                                                                 \
  }                                                                                                                  \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::__func(bool& __pass)

#define TEST10(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10)                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10 {                   \
  void __func(bool& __pass);                                                                           \
  struct __register {                                                                                 \
    __register() {                                                                                    \
      multi_level_test_case::add_test_case(                                                           \
          {#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10}, __func); \
    }                                                                                                 \
  } __register_func;                                                                                  \
  }                                                                                                   \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::__func(bool& __pass)

#define TEST11(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11)                  \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11 {                    \
  void __func(bool& __pass);                                                                                    \
  struct __register {                                                                                          \
    __register() {                                                                                             \
      multi_level_test_case::add_test_case(                                                                    \
          {#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10, #name11}, __func); \
    }                                                                                                          \
  } __register_func;                                                                                           \
  }                                                                                                            \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::__func(bool& __pass)

#define TEST12(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12)          \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12 {            \
  void __func(bool& __pass);                                                                                    \
  struct __register {                                                                                          \
    __register() {                                                                                             \
      multi_level_test_case::add_test_case(                                                                    \
          {#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10, #name11, #name12}, \
          __func);                                                                                             \
    }                                                                                                          \
  } __register_func;                                                                                           \
  }                                                                                                            \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::__func(bool& __pass)

#define TEST13(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13)       \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13 {         \
  void __func(bool& __pass);                                                                                         \
  struct __register {                                                                                               \
    __register() {                                                                                                  \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, \
                                            #name10, #name11, #name12, #name13},                                    \
                                           __func);                                                                 \
    }                                                                                                               \
  } __register_func;                                                                                                \
  }                                                                                                                 \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::__func(       \
      bool& __pass)

#define TEST14(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14) \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14 {   \
  void __func(bool& __pass);                                                                                           \
  struct __register {                                                                                                 \
    __register() {                                                                                                    \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9,   \
                                            #name10, #name11, #name12, #name13, #name14},                             \
                                           __func);                                                                   \
    }                                                                                                                 \
  } __register_func;                                                                                                  \
  }                                                                                                                   \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::__func( \
      bool& __pass)

#define TEST15(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15)                                                                                                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15 {                                                                                                         \
  void __func(bool& __pass);                                                                                            \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10,     \
                                  #name11, #name12, #name13, #name14, #name15},                                        \
                                 __func);                                                                              \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      __func(bool& __pass)

#define TEST16(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15, name16)                                                                                         \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15::name16 {                                                                                                 \
  void __func(bool& __pass);                                                                                            \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9,    \
                                            #name10, #name11, #name12, #name13, #name14, #name15, #name16},            \
                                           __func);                                                                    \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      name16::__func(bool& __pass)

#define TEST17(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15, name16, name17)                                                                                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15::name16::name17 {                                                                                         \
  void __func(bool& __pass);                                                                                            \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add_test_case({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9,    \
                                            #name10, #name11, #name12, #name13, #name14, #name15, #name16, #name17},   \
                                           __func);                                                                    \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      name16::name17::__func(bool& __pass)

#endif  // SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
