#ifndef SHE_TEST_H
#define SHE_TEST_H

#include "command_line/options.h"
#include "command_line/parser.h"
#include "format/color.h"
#include "format/fmt.h"
#include "format/gtest.h"
#include "format/style_v1.h"
#include "format/template_format.h"
#include "test_case_registry/multi_level_test_case.h"
#include "test_tools/equal.h"
#include "run_all_test.h"

namespace she_test {
constexpr int major       = 1;
constexpr int minor       = 0;
constexpr int patch       = 0;
const std::string version = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}  // namespace she_test

#endif  // SHE_TEST_H
