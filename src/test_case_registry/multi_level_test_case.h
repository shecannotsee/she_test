#ifndef SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
#define SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H

#include <functional>
#include <string>

class multi_level_test_case {
  using test_case_name = std::vector<std::string>;
  static auto test_case_name_to_string(const test_case_name& names) -> std::string;

  using test_case_func = std::function<void()>;
  std::unordered_map<std::string, test_case_func> test_case_table_;
  std::vector<test_case_name> test_case_list_;

  multi_level_test_case() = default;

  static auto get_instance() -> multi_level_test_case&;

  void add(const test_case_name& name, const test_case_func& func);

  void run(const test_case_name& name);

 public:
  static void add_test_case(const std::vector<std::string>& name, const std::function<void()>& func) {
    get_instance().add(name, func);
  }

  static auto get_test_case_list() -> std::vector<std::vector<std::string>> {
    return get_instance().test_case_list_;
  }

  static void run_test_case(const std::vector<std::string>& test_case_name) {
    get_instance().run(test_case_name);
  }
};

#define TEST(name1, name2)                                  \
  namespace name1::name2 {                                  \
  void __func();                                            \
  struct __register {                                       \
    __register() {                                          \
      multi_level_test_case::add({#name1, #name2}, __func); \
    }                                                       \
  } __register_func;                                        \
  }                                                         \
  void name1::name2::__func()

#define TEST1(name1)                                \
  namespace name1 {                                 \
  void __func();                                    \
  struct __register {                               \
    __register() {                                  \
      multi_level_test_case::add({#name1}, __func); \
    }                                               \
  } __register_func;                                \
  }                                                 \
  void name1::__func()

#define TEST2(name1, name2)                                 \
  namespace name1::name2 {                                  \
  void __func();                                            \
  struct __register {                                       \
    __register() {                                          \
      multi_level_test_case::add({#name1, #name2}, __func); \
    }                                                       \
  } __register_func;                                        \
  }                                                         \
  void name1::name2::__func()

#define TEST3(name1, name2, name3)                                  \
  namespace name1::name2::name3 {                                   \
  void __func();                                                    \
  struct __register {                                               \
    __register() {                                                  \
      multi_level_test_case::add({#name1, #name2, #name3}, __func); \
    }                                                               \
  } __register_func;                                                \
  }                                                                 \
  void name1::name2::name3::__func()

#define TEST4(name1, name2, name3, name4)                                   \
  namespace name1::name2::name3::name4 {                                    \
  void __func();                                                            \
  struct __register {                                                       \
    __register() {                                                          \
      multi_level_test_case::add({#name1, #name2, #name3, #name4}, __func); \
    }                                                                       \
  } __register_func;                                                        \
  }                                                                         \
  void name1::name2::name3::name4::__func()

#define TEST5(name1, name2, name3, name4, name5)                                    \
  namespace name1::name2::name3::name4::name5 {                                     \
  void __func();                                                                    \
  struct __register {                                                               \
    __register() {                                                                  \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5}, __func); \
    }                                                                               \
  } __register_func;                                                                \
  }                                                                                 \
  void name1::name2::name3::name4::name5::__func()

#define TEST6(name1, name2, name3, name4, name5, name6)                                     \
  namespace name1::name2::name3::name4::name5::name6 {                                      \
  void __func();                                                                            \
  struct __register {                                                                       \
    __register() {                                                                          \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6}, __func); \
    }                                                                                       \
  } __register_func;                                                                        \
  }                                                                                         \
  void name1::name2::name3::name4::name5::name6::__func()

#define TEST7(name1, name2, name3, name4, name5, name6, name7)                                      \
  namespace name1::name2::name3::name4::name5::name6::name7 {                                       \
  void __func();                                                                                    \
  struct __register {                                                                               \
    __register() {                                                                                  \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7}, __func); \
    }                                                                                               \
  } __register_func;                                                                                \
  }                                                                                                 \
  void name1::name2::name3::name4::name5::name6::name7::__func()

#define TEST8(name1, name2, name3, name4, name5, name6, name7, name8)                                       \
  namespace name1::name2::name3::name4::name5::name6::name7::name8 {                                        \
  void __func();                                                                                            \
  struct __register {                                                                                       \
    __register() {                                                                                          \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8}, __func); \
    }                                                                                                       \
  } __register_func;                                                                                        \
  }                                                                                                         \
  void name1::name2::name3::name4::name5::name6::name7::name8::__func()

#define TEST9(name1, name2, name3, name4, name5, name6, name7, name8, name9)                                        \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9 {                                         \
  void __func();                                                                                                    \
  struct __register {                                                                                               \
    __register() {                                                                                                  \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9}, __func); \
    }                                                                                                               \
  } __register_func;                                                                                                \
  }                                                                                                                 \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::__func()

#define TEST10(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10)                               \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10 {                                 \
  void __func();                                                                                                    \
  struct __register {                                                                                               \
    __register() {                                                                                                  \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10}, \
                                 __func);                                                                           \
    }                                                                                                               \
  } __register_func;                                                                                                \
  }                                                                                                                 \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::__func()

#define TEST11(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11)                  \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11 {                    \
  void __func();                                                                                               \
  struct __register {                                                                                          \
    __register() {                                                                                             \
      multi_level_test_case::add(                                                                              \
          {#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10, #name11}, __func); \
    }                                                                                                          \
  } __register_func;                                                                                           \
  }                                                                                                            \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::__func()

#define TEST12(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12)          \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12 {            \
  void __func();                                                                                               \
  struct __register {                                                                                          \
    __register() {                                                                                             \
      multi_level_test_case::add(                                                                              \
          {#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10, #name11, #name12}, \
          __func);                                                                                             \
    }                                                                                                          \
  } __register_func;                                                                                           \
  }                                                                                                            \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::__func()

#define TEST13(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13)      \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13 {        \
  void __func();                                                                                                   \
  struct __register {                                                                                              \
    __register() {                                                                                                 \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10, \
                                  #name11, #name12, #name13},                                                      \
                                 __func);                                                                          \
    }                                                                                                              \
  } __register_func;                                                                                               \
  }                                                                                                                \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::__func()

#define TEST14(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14) \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14 {   \
  void __func();                                                                                                      \
  struct __register {                                                                                                 \
    __register() {                                                                                                    \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10,    \
                                  #name11, #name12, #name13, #name14},                                                \
                                 __func);                                                                             \
    }                                                                                                                 \
  } __register_func;                                                                                                  \
  }                                                                                                                   \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::__func()

#define TEST15(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15)                                                                                                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15 {                                                                                                         \
  void __func();                                                                                                       \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10,     \
                                  #name11, #name12, #name13, #name14, #name15},                                        \
                                 __func);                                                                              \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      __func()

#define TEST16(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15, name16)                                                                                         \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15::name16 {                                                                                                 \
  void __func();                                                                                                       \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10,     \
                                  #name11, #name12, #name13, #name14, #name15, #name16},                               \
                                 __func);                                                                              \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      name16::__func()

#define TEST17(name1, name2, name3, name4, name5, name6, name7, name8, name9, name10, name11, name12, name13, name14,  \
               name15, name16, name17)                                                                                 \
  namespace name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::    \
      name15::name16::name17 {                                                                                         \
  void __func();                                                                                                       \
  struct __register {                                                                                                  \
    __register() {                                                                                                     \
      multi_level_test_case::add({#name1, #name2, #name3, #name4, #name5, #name6, #name7, #name8, #name9, #name10,     \
                                  #name11, #name12, #name13, #name14, #name15, #name16, #name17},                      \
                                 __func);                                                                              \
    }                                                                                                                  \
  } __register_func;                                                                                                   \
  }                                                                                                                    \
  void name1::name2::name3::name4::name5::name6::name7::name8::name9::name10::name11::name12::name13::name14::name15:: \
      name16::name17::__func()

#endif  // SHE_TEST_TEST_CASE_REGISTRY_MULTI_LEVEL_TEST_CASE_H
