#pragma once

#include <cstddef>
#include <string>
#include <map>
#include <stdexcept>

namespace nucleotide_count
{
    std::map<char, int> count(const std::string& strand);
}  // namespace nucleotide_count
