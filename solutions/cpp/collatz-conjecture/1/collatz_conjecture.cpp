#include "collatz_conjecture.h"

namespace collatz_conjecture
{
    int steps(int value)
    {
        if(value <= 0)
        {
            throw std::domain_error("Invalid value");
        }

        int steps = 0;
        
        while(true)
        {
            if(value == 1)
            {
                break;
            }

            if(value % 2)
            {
                value = (value * 3) + 1;
            }
            else
            {
                value /= 2;
            }

            ++steps;
        }

        return steps;
    }
}  // namespace collatz_conjecture
