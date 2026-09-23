#include "grains.h"

namespace grains
{
    unsigned long long square(int current_square_index)
    {
        unsigned long long current_square_value = 1;

        for(int i = 1; i < current_square_index; ++i)
        {
            current_square_value += current_square_value;
        }

        return current_square_value;
    }
    
    unsigned long long total()
    {
        unsigned long long current_square_total = 0;

        for(int i = 1; i <= 64; ++i)
        {
            current_square_total += square(i);
        }

        return current_square_total;
    }
}  // namespace grains
