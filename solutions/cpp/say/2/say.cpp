#include "say.h"

#include <cstddef>
#include <stdexcept>

using namespace std;

namespace
{
    void add_space_if_needed(string& number_in_english)
    {
        if(!number_in_english.empty() && number_in_english.back() != ' ')
        {
            number_in_english += " ";
        }
    }
    
    void ones(string& number_as_string, string& number_in_english)
    {
        if(!number_as_string.empty())
        {
            char current_number = number_as_string.at(0);
    
            number_as_string.erase(0, 1);
            
            switch(current_number)
            {
                case '0':
                    if(number_in_english.empty())
                    {
                        number_in_english += "zero";
                    }
                    
                    break;
    
                case '1':
                    number_in_english += "one";
                    
                    break;
    
                case '2':
                    number_in_english += "two";
                    
                    break;
    
                case '3':
                    number_in_english += "three";
                    
                    break;
    
                case '4':
                    number_in_english += "four";
                    
                    break;
    
                case '5':
                    number_in_english += "five";
                    
                    break;
    
                case '6':
                    number_in_english += "six";
                    
                    break;
    
                case '7':
                    number_in_english += "seven";
                    
                    break;
    
                case '8':
                    number_in_english += "eight";
                    
                    break;
    
                case '9':
                    number_in_english += "nine";
                    
                    break;
    
                default:
                    break;
            }
        }
    }
    
    void tens(string& number_as_string, string& number_in_english)
    {
        if(number_as_string.size() >= 2)
        {            
            char current_number = number_as_string.at(0);
    
            number_as_string.erase(0, 1);
            
            switch(current_number)
            {
                case '0':
                    if(number_as_string.at(0) != '0')
                    {
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
                case '1':
                {
                    add_space_if_needed(number_in_english);
                    
                    char next_number = number_as_string.at(0);
    
                    number_as_string.erase(0, 1);
    
                    switch(next_number)
                    {
                        case '0':
                            number_in_english += "ten";
    
                            break;
    
                        case '1':
                            number_in_english += "eleven";
    
                            break;
    
                        case '2':
                            number_in_english += "twelve";
    
                            break;
    
                        case '3':
                            number_in_english += "thirteen";
    
                            break;
    
                        case '4':
                            number_in_english += "fourteen";
    
                            break;
    
                        case '5':
                            number_in_english += "fifteen";
    
                            break;
    
                        case '6':
                            number_in_english += "sixteen";
    
                            break;
    
                        case '7':
                            number_in_english += "seventeen";
    
                            break;
    
                        case '8':
                            number_in_english += "eighteen";
    
                            break;
    
                        case '9':
                            number_in_english += "nineteen";
    
                            break;
    
                        default:
                            break;
                    }

                    break;
                }
                
                case '2':
                    add_space_if_needed(number_in_english);
                            
                    number_in_english += "twenty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '3':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "thirty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '4':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "forty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '5':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "fifty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '6':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "sixty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '7':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "seventy";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '8':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "eighty";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                case '9':
                    add_space_if_needed(number_in_english);
                    
                    number_in_english += "ninety";
    
                    if(number_as_string.at(0) != '0')
                    {
                        number_in_english += "-";
                        ones(number_as_string, number_in_english);
                    }
                    else
                    {
                        number_as_string.erase(0, 1);
                    }
                    
                    break;
    
                default:
                    break;
            }
        }

        if(number_as_string.size() == 1)
        {
            ones(number_as_string, number_in_english);
        }
    }
    
    void hundreds(string& number_as_string, string& number_in_english)
    {
        if(number_as_string.size() >= 3)
        {
            if(number_as_string.at(0) != '0')
            {
                add_space_if_needed(number_in_english);
                
                ones(number_as_string, number_in_english);
    
                number_in_english += " hundred";
            }
            else
            {
                number_as_string.erase(0, 1);
            }
        }

        tens(number_as_string, number_in_english);
    }
    
    void thousands(string& number_as_string, string& number_in_english)
    {
        if(!number_as_string.empty())
        {
            while(number_as_string.at(0) == '0' && number_as_string.size() >= 4)
            {                
                number_as_string.erase(0, 1);
            }
            
            const size_t number_as_string_size = number_as_string.size();
            
            if(number_as_string_size >= 4)
            {
                add_space_if_needed(number_in_english);
    
                switch(number_as_string_size)
                {
                    case 6:
                        hundreds(number_as_string, number_in_english);
    
                        break;
    
                    case 5:
                        tens(number_as_string, number_in_english);
    
                        break;
    
                    case 4:
                        ones(number_as_string, number_in_english);
    
                        break;
    
                    default:
                        break;
                }
    
                number_in_english += " thousand";
            }
    
            hundreds(number_as_string, number_in_english);
        }
    }
    
    void millions(string& number_as_string, string& number_in_english)
    {
        if(!number_as_string.empty())
        {
            while(number_as_string.at(0) == '0' && number_as_string.size() >= 7)
            {                
                number_as_string.erase(0, 1);
            }
            
            const size_t number_as_string_size = number_as_string.size();
            
            if(number_as_string_size >= 7)
            {
                add_space_if_needed(number_in_english);
        
                switch(number_as_string_size)
                {
                    case 9:
                        hundreds(number_as_string, number_in_english);
        
                        break;
        
                    case 8:
                        tens(number_as_string, number_in_english);
        
                        break;
        
                    case 7:
                        ones(number_as_string, number_in_english);
        
                        break;
        
                    default:
                        break;
                }
        
                number_in_english += " million";
            }
            
            thousands(number_as_string, number_in_english);
        }
    }
    
    void billions(string& number_as_string, string& number_in_english)
    {
        if(!number_as_string.empty())
        {
            while(number_as_string.at(0) == '0' && number_as_string.size() >= 10)
            {                
                number_as_string.erase(0, 1);
            }
            
            const size_t number_as_string_size = number_as_string.size();
            
            if(number_as_string_size >= 10)
            {
                add_space_if_needed(number_in_english);
        
                switch(number_as_string_size)
                {
                    case 12:
                        hundreds(number_as_string, number_in_english);
        
                        break;
        
                    case 11:
                        tens(number_as_string, number_in_english);
        
                        break;
        
                    case 10:
                        ones(number_as_string, number_in_english);
        
                        break;
        
                    default:
                        break;
                }
        
                number_in_english += " billion";
            }
            
            millions(number_as_string, number_in_english);
        }
    }
}

namespace say
{
    string in_english(long int number)
    {
        if(number < 0 || number > 999'999'999'999)
        {
            throw domain_error("Invalid value");
        }

        string number_in_english = "";

        string number_as_string = to_string(number);

        billions(number_as_string, number_in_english);
        
        return number_in_english;
    }
}  // namespace say
