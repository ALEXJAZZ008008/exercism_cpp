#include "difference_of_squares.h"

namespace difference_of_squares
{
    unsigned long long square_of_sum(unsigned long long n)
    {
        unsigned long long output = 0;

        for(unsigned long long i = 1; i <= n; ++i)
        {
            output += i;
        }
        
        return output *= output;
    }
    
    unsigned long long sum_of_squares(unsigned long long n)
    {
        unsigned long long output = 0;

        for(unsigned long long i = 1; i <= n; ++i)
        {
            output += (i * i);
        }
        
        return output;
    }
    
    unsigned long long difference(unsigned long long n)
    {
        unsigned long long square_of_sum_output = square_of_sum(n);
        unsigned long long sum_of_squares_output = sum_of_squares(n);

        unsigned long long output = {};
        
        if(sum_of_squares_output >= square_of_sum_output)
        {
            output = sum_of_squares_output - square_of_sum_output;
        }
        else
        {
            output = square_of_sum_output - sum_of_squares_output;
        }
        
        return output;
    }
}  // namespace difference_of_squares
