#include "nth_prime.h"

namespace nth_prime
{
    int nth(int n)
    {
        if (n <= 0)
        {
            throw std::domain_error("n must be positive");
        }

        int i = 2;
        int primes_found = 0;
        int most_recent_prime_found = {};

        while(true)
        {
            if(primes_found == n)
            {
                break;
            }

            bool i_is_prime = true;
            
            for(int j = 2; j < i; ++j)
            {
                if(i % j == 0)
                {
                    i_is_prime = false;

                    break;
                }
            }

            if(i_is_prime)
            {
                most_recent_prime_found = i;
                ++primes_found;
            }

            ++i;
        }

        return most_recent_prime_found;
    }
}  // namespace nth_prime
