#include "sieve.h"

namespace sieve
{
    std::vector<int> primes(int n)
    {
        std::vector<int> primes_up_to_n = {};

        if(n >= 1)
        {
            std::vector<bool> markers(n + 1, false);
    
            for(int i = 2; i <= n; ++i)
            {
                if(!markers.at(i))
                {
                    primes_up_to_n.push_back(i);
                    
                    int multiple_iterator = 2;
                    int multiple = i * multiple_iterator;
        
                    while(multiple <= n)
                    {
                        markers.at(multiple) = true;
    
                        ++multiple_iterator;
                        multiple = i * multiple_iterator;
                    }
                }
            }
        }

        return primes_up_to_n;
    }
}  // namespace sieve
