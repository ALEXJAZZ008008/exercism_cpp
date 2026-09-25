#pragma once

#include <vector>

namespace sum_of_multiples
{
    std::vector<int> get_multiples(int item_level, int stage_level);
    
    int to(std::vector<int> item_levels, int stage_level);
}  // namespace sum_of_multiples
