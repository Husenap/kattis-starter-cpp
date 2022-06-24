#include "shared_format.hpp"

#include <gtest/gtest.h>

TEST(shared, string_format) {
  EXPECT_EQ(shared::format("({}, {})", 42, 1337), "(42, 1337)");
  EXPECT_EQ(shared::format("{} + {} = {}", "hello", "world", "hello world"),
            "hello + world = hello world");
  EXPECT_EQ(shared::format("{} {} {}", "9", '9', 9), "9 9 9");
}