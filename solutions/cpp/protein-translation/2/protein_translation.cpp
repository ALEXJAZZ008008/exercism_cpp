#include "protein_translation.h"

using namespace std;

namespace protein_translation
{
    std::string_view rna_to_protein_parser::consume_codon()
    {
        std::string_view consumed_codon = peek_codon();

        position_ += codon_length_;
                
        return consumed_codon;
    }

    bool rna_to_protein_parser::is_stop_codon(std::string_view codon)
    {
        return stop_codons_.find(codon) != stop_codons_.end();
    }
    
    vector<string> rna_to_protein_parser::to_proteins()
    {
        position_ = 0;
        
        vector<string> protein_sequence = {};
        protein_sequence.reserve(input_.size() / codon_length_);
        
        while(has_next_codon() && !is_stop_codon(peek_codon()))
        {
            protein_sequence.emplace_back(codon_to_protein_.at(consume_codon()));
        }

        return protein_sequence;
    }
    
    vector<string> proteins(string rna_sequence)
    {
        rna_to_protein_parser parser(move(rna_sequence));
        return parser.to_proteins();
    }
}  // namespace protein_translation
