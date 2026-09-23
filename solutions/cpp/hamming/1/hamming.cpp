#include "hamming.h"

namespace hamming
{
    int compute(const std::string& first_strand, const std::string& second_strand)
    {
        long unsigned int first_strand_size = first_strand.size();

        if(first_strand_size != second_strand.size())
        {
            throw std::domain_error("Invalid value");
        }

        int hamming_distance = 0;

        for(long unsigned int i = 0; i < first_strand_size; ++i)
        {
            if(first_strand.at(i) != second_strand.at(i))
            {
                ++hamming_distance;
            }
        }

        return hamming_distance;
    }
}  // namespace hamming
