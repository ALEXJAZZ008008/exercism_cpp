#include "rna_transcription.h"

namespace rna_transcription
{
    char to_rna(char dna_sequence)
    {
        char rna_sequence = {};

        switch(dna_sequence)
        {
            case 'C':
                rna_sequence = 'G';

                break;

            case 'G':
                rna_sequence = 'C';

                break;

            case 'A':
                rna_sequence = 'U';

                break;

            case 'T':
                rna_sequence = 'A';

                break;

            default:
                break;
        }

        return rna_sequence;
    }
    
    std::string to_rna(std::string dna_sequence)
    {
        std::string rna_sequence = "";
        
        for(std::size_t i = 0; i < dna_sequence.size(); ++i)
        {
            rna_sequence += to_rna(dna_sequence.at(i));
        }

        return rna_sequence;
    }
}  // namespace rna_transcription
