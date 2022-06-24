#pragma once

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace shared {

inline std::vector<std::string> split(const std::string& s, char delimiter) {
  std::vector<std::string> tokens;
  std::string              token;
  std::istringstream       tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

template <typename TransformFunc>
inline auto split(const std::string& s, char delimiter, TransformFunc transform) {
  const auto                          splits = split(s, delimiter);
  std::vector<decltype(transform(s))> tokens;
  for (const auto& token : splits) {
    tokens.push_back(transform(token));
  }
  return tokens;
}

template <typename TransformFunc>
inline auto safe_split(const std::string& s, char delimiter, TransformFunc transform) {
  const auto                                         splits = split(s, delimiter);
  std::vector<std::optional<decltype(transform(s))>> tokens;
  for (const auto& token : splits) {
    try {
      tokens.push_back(transform(token));
    } catch (...) {
      tokens.push_back(std::nullopt);
    }
  }
  return tokens;
}

}  // namespace shared
