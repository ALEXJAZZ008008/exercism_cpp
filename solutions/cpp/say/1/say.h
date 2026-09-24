#pragma once

#include <string>

namespace say
{
    void ones(std::string& number_as_string, std::string& number_in_english);
    void tens(std::string& number_as_string, std::string& number_in_english);
    void hundreds(std::string& number_as_string, std::string& number_in_english);
    void thousands(std::string& number_as_string, std::string& number_in_english);
    void millions(std::string& number_as_string, std::string& number_in_english);
    void billions(std::string& number_as_string, std::string& number_in_english);
    
    std::string in_english(long int number);
}  // namespace say
