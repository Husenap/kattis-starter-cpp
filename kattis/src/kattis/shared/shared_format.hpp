#pragma once

#include <optional>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

namespace shared {

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

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  out << "[";
  for (std::size_t i = 0; i < v.size(); ++i) {
    if (i > 0) out << ", ";
    out << v[i];
  }
  out << "]";
  return out;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  shared::format_to(out, "({},{})", p.first, p.second);
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::optional<T>& p) {
  if (p) {
    out << *p;
  } else {
    out << "{nullopt}";
  }
  return out;
}

template <typename T, size_t N, typename = std::enable_if_t<!std::is_same<T, char>::value>>
std::ostream& operator<<(std::ostream& out, const T (&a)[N]) {
  out << "[";
  for (std::size_t i = 0; i < N; ++i) {
    if (i > 0) out << ", ";
    out << a[i];
  }
  out << "]";
  return out;
}