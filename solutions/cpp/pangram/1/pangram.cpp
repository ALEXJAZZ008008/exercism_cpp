#include "pangram.h"

namespace pangram
{
    bool is_pangram(std::string sentence)
    {
        bool sentence_is_a_pangram = false;
        
        if(sentence.size() > 0)
        {
            std::array<bool, 26> does_letter_exist = {};
    
            for(long unsigned int i = 0; i <= sentence.size() - 1; ++i)
            {
                sentence.at(i) = std::tolower(sentence.at(i));
                
                if(sentence.at(i) >= 'a' and sentence.at(i) <= 'z')
                {
                    does_letter_exist.at(sentence.at(i) - 'a') = true;
                }
            }
    
            sentence_is_a_pangram = true;
    
            for(long unsigned int i = 0; i <= does_letter_exist.size() - 1; ++i)
            {
                if(!does_letter_exist.at(i))
                {
                    sentence_is_a_pangram = false;
    
                    break;
                }
            }
        }

        return sentence_is_a_pangram;
    }
}  // namespace pangram
