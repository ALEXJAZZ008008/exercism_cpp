#pragma once

#include <vector>
#include <string>
#include <map>

namespace protein_translation
{
    class rna_to_protein_parser
    {
        private:
            std::string input_ = "";
            std::size_t position_ = 0;
            std::vector<std::string> output_ = {};

            inline static const std::map<std::string, std::string> proteins_ = {{"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"}, {"UUA", "Leucine"}, {"UUG", "Leucine"}, {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"}, {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"}, {"UGU", "Cysteine"}, {"UGC", "Cysteine"}, {"UGG", "Tryptophan"}, {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}};
            
            std::size_t remaining() const {return (input_.size() - position_) / 3;}
            std::string peek() const {return input_.substr(position_, 3);}
            
            std::string consume()
            {
                std::string consumed_string = peek();

                position_ = position_ + 3;
                
                return consumed_string;
            }
        
        public:
            explicit rna_to_protein_parser(const std::string& rna_sequence) : input_(rna_sequence){}
            
            std::vector<std::string> to_proteins();
    };

    std::vector<std::string> proteins(std::string rna_sequence);
}  // namespace protein_translation
