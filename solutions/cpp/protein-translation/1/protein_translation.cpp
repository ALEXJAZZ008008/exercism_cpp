#include "protein_translation.h"

using namespace std;

namespace protein_translation
{
    vector<string> rna_to_protein_parser::to_proteins()
    {
        vector<string> protein_sequence = {};
        
        while(remaining() > 0)
        {
            string current_protein = proteins_.at(consume());

            if(current_protein == "STOP")
            {
                break;
            }

            protein_sequence.push_back(current_protein);
        }

        return protein_sequence;
    }
    
    vector<string> proteins(string rna_sequence)
    {
        rna_to_protein_parser parser(rna_sequence);
        return parser.to_proteins();
    }
}  // namespace protein_translation
