#pragma once

#include <istream>

namespace _addtwonumbers {

inline void solve(std::istream& in, std::ostream& out) {
  int a, b;
  in >> a >> b;
  out << (a + b) << std::endl;
}

}  // namespace _addtwonumbers
