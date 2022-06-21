#include "test_runner.hpp"

inline void rtrim(std::string &s) {
  s.erase(
      std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),
      s.end());
}
inline void trim(std::string &s) {
  rtrim(s);
}

void run_tests(std::filesystem::path directoryName, Solver solver) {
  ASSERT_TRUE(std::filesystem::exists(directoryName));

  for (auto &p : std::filesystem::directory_iterator(directoryName)) {
    if (p.path().extension() == ".in") {
      const std::filesystem::path inPath  = p.path();
      std::filesystem::path       ansPath = inPath;
      ansPath.replace_extension(".ans");

      std::ifstream in(inPath);
      std::ifstream ans(ansPath);
      std::string   expectedAnswer((std::istreambuf_iterator<char>(ans)),
                                 std::istreambuf_iterator<char>());

      std::stringstream out;

      solver(in, out);
      auto answer = out.str();

      trim(expectedAnswer);
      trim(answer);

      std::string prefix = inPath.generic_string() + " \n";
      answer             = prefix + answer;
      expectedAnswer     = prefix + expectedAnswer;

      EXPECT_EQ(answer, expectedAnswer);
    }
  }
}