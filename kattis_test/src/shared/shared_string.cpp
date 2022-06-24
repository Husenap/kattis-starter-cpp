#include "shared_string.hpp"

#include <gtest/gtest.h>

TEST(shared, string_split) {
  {
    const auto result = shared::split("a,b,c,d", ',');
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result, std::vector<std::string>({"a", "b", "c", "d"}));
  }
  {
    const auto result = shared::split("hello world string splitter", ' ');
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result, std::vector<std::string>({"hello", "world", "string", "splitter"}));
  }
}

TEST(shared, string_format) {
  EXPECT_EQ(shared::format("({}, {})", 42, 1337), "(42, 1337)");
  EXPECT_EQ(shared::format("{} + {} = {}", "hello", "world", "hello world"),
            "hello + world = hello world");
  EXPECT_EQ(shared::format("{} {} {}", "9", '9', 9), "9 9 9");
}