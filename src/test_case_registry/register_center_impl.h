#include "register_center.h"

template <typename T>
void she_test::register_center<T>::add_test(const std::string& suite_name,
                                            const std::string& test_name,
                                            const details::test_function& test_func) {
  test_case::add(suite_name, test_name, test_func);
}

template <typename T>
void she_test::register_center<T>::init_and_run(int argc, char** argv) {
  using namespace details;
  const auto all_test = test_case::get_all();
  std::vector<std::tuple<std::string, std::string>> run_list;
  // filter from command_line
  parser::get_instance().parse(argc, argv);
  for (const auto& op : parser::get_instance().get_ops()) {
    switch (op.key) {
      case options::VERSION: {
        std::cout << "she_test version " << version << std::endl;
        return;
      }
      case options::HELP: {
        std::cout << help_message << std::endl;
        return;
      }
      case options::LIST_ALL_TESTS: {
        for (const auto& test : test_case::get_all()) {
          std::cout << std::get<0>(test) << "." << std::get<1>(test) << std::endl;
        }
        return;
      }
      case options::RUN_SOME_TESTS: {
        for (const auto& test_cases : op.value) {
          try {
            auto ret = parser::split_suite_name_and_test_case(test_cases);
            run_list.emplace_back(std::get<0>(ret), std::get<1>(ret));
          } catch (const std::runtime_error& ex) {
            std::cout << "The format is incorrect or does not exist :" << ex.what() << std::endl;
          }
        }
        break;
      }
      case options::EXCLUDE_SOME_TESTS: {
        if (run_list.empty()) {
          run_list = all_test;
        }
        std::cout << "exclude:\n";
        for (const auto& test_cases : op.value) {
          try {
            auto ret = parser::split_suite_name_and_test_case(test_cases);
            for (int i = 0; i < run_list.size(); ++i) {
              bool exclude_cond =
                  (std::get<0>(run_list[i]) == std::get<0>(ret)) && (std::get<1>(run_list[i]) == std::get<1>(ret));
              if (exclude_cond) {
                run_list.erase(run_list.begin() + i);
                break;
              }
            }
          } catch (const std::runtime_error& ex) {
            std::cout << "The format is incorrect or does not exist :" << ex.what() << std::endl;
          }
        }
        break;
      }
      case options::RUN_ALL_TESTS: {
        run_list = all_test;
        break;
      }
      case options::UNKNOWN: {
        std::cout << "error options:\n";
        for (const auto& error_options : op.value) {
          std::cout << error_options << std::endl;
        }
        return;
      }
      default: {
        std::cout << "Unknown error\n";
        return;
      }
    }  // switch
  }
  test_case::run_all<T>(run_list);
}
