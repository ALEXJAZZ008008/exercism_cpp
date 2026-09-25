#pragma once

#include <cstddef>
#include <string>

namespace say
{
    class number_to_english_parser
    {
        private:
            std::string input_ = "";
            std::size_t position_ = 0;
            std::string output_ = "";
            
            std::size_t remaining() const {return input_.size() - position_;}
            char peek() const {return input_.at(position_);}
            char consume(){return input_.at(position_++);}
            
            void add_space_if_needed();
            void add_tens_word(char current_number);
            void add_scale_word(std::size_t minimum_size, const std::string& scale_word);
            
            void ones();
            void tens();
            void hundreds();
            void thousands();
            void millions();
            void billions();
        
        public:
            explicit number_to_english_parser(long long number);
            
            std::string to_english();
    };

    std::string in_english(long long number);
}  // namespace say
