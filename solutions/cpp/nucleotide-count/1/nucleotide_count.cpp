#include "nucleotide_count.h"

namespace nucleotide_count
{
    std::map<char, int> count(const std::string& strand)
    {
        std::map<char, int> strand_nucleotide_count = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

        for(std::size_t i = 0; i < strand.size(); ++i)
        {
            char strand_char_at_i = strand.at(i);
            
            if(strand_char_at_i != 'A' && strand_char_at_i != 'C' && strand_char_at_i != 'G' && strand_char_at_i != 'T')
            {
                throw std::invalid_argument("Invalid argument");
            }

            ++strand_nucleotide_count.at(strand_char_at_i);
        }
        
        return strand_nucleotide_count;
    }
}  // namespace nucleotide_count
