#pragma once

#include <cstddef>
#include <utility>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_set>
#include <unordered_map>

namespace protein_translation
{
    class rna_to_protein_parser
    {
        private:
            std::string input_ = "";
            std::size_t position_ = 0;

            static constexpr std::size_t codon_length_ = 3;
            inline static const std::unordered_set<std::string_view> stop_codons_ = {"UAA", "UAG", "UGA"};
            inline static const std::unordered_map<std::string_view, std::string_view> codon_to_protein_ = {{"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"}, {"UUA", "Leucine"}, {"UUG", "Leucine"}, {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"}, {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"}, {"UGU", "Cysteine"}, {"UGC", "Cysteine"}, {"UGG", "Tryptophan"}};
            
            bool has_next_codon() const {return position_ + codon_length_ <= input_.size();}
            std::string_view peek_codon() const {return std::string_view{input_}.substr(position_, codon_length_);}
            
            std::string_view consume_codon();
            static bool is_stop_codon(std::string_view codon);
        
        public:
            explicit rna_to_protein_parser(std::string rna_sequence) : input_(std::move(rna_sequence)){}
            
            std::vector<std::string> to_proteins();
    };

    std::vector<std::string> proteins(std::string rna_sequence);
}  // namespace protein_translation
