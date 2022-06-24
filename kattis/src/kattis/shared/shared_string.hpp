#pragma once

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

template <typename... Args>
inline void format_to(std::ostream& out, std::string_view format_string, Args&&... args) {
  ((out << format_string.substr(0, format_string.find("{}")),
    format_string.remove_prefix(format_string.find("{}") + 2),
    out << args),
   ...);
  out << format_string;
}

template <typename... Args>
inline auto format(std::string_view format_string, Args&&... args) {
  std::ostringstream output;
  format_to(output, format_string, std::forward<Args>(args)...);
  return output.str();
}

}  // namespace shared