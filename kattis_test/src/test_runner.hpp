#pragma once

#include <filesystem>
#include <functional>

using Solver = std::function<void(std::istream &, std::ostream &)>;
void run_tests(std::filesystem::path directoryName, Solver solver);
