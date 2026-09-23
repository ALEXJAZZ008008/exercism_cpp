#pragma once

#include <string>
#include <stdexcept>

namespace hamming
{
    int compute(const std::string& first_strand, const std::string& second_strand);
}  // namespace hamming
