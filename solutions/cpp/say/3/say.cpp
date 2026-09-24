#include "say.h"

#include <stdexcept>

using namespace std;

namespace say
{    
    void number_to_english_parser::add_space_if_needed()
    {
        if(!output_.empty() && output_.back() != ' ')
        {
            output_ += " ";
        }
    }

    void number_to_english_parser::add_tens_word(char current_number)
    {
        switch(current_number)
        {                
            case '2':
                output_ += "twenty";

                break;

            case '3':
                output_ += "thirty";

                break;

            case '4':
                output_ += "forty";

                break;

            case '5':
                output_ += "fifty";

                break;

            case '6':
                output_ += "sixty";

                break;

            case '7':
                output_ += "seventy";

                break;

            case '8':
                output_ += "eighty";

                break;

            case '9':
                output_ += "ninety";

                break;

            default:
                break;
        }
    }

    void number_to_english_parser::add_scale_word(size_t minimum_size, const string& scale_word)
    {
        while(remaining() >= minimum_size && peek() == '0')
        {                
            consume();
        }
                
        const size_t input_remaining = remaining();
                
        if(input_remaining >= minimum_size)
        {
            add_space_if_needed();
        
            switch(input_remaining - minimum_size)
            {
                case 2:
                    hundreds();
        
                    break;
        
                case 1:
                    tens();
        
                    break;
        
                case 0:
                    ones();
        
                    break;
        
                default:
                    break;
            }
        
            output_ += scale_word;
        }
    }
    
    void number_to_english_parser::ones()
    {
        if(remaining() > 0)
        {
            const char current_number = consume();
            
            switch(current_number)
            {
                case '0':
                    if(output_.empty())
                    {
                        output_ += "zero";
                    }
                    
                    break;
    
                case '1':
                    output_ += "one";
                    
                    break;
    
                case '2':
                    output_ += "two";
                    
                    break;
    
                case '3':
                    output_ += "three";
                    
                    break;
    
                case '4':
                    output_ += "four";
                    
                    break;
    
                case '5':
                    output_ += "five";
                    
                    break;
    
                case '6':
                    output_ += "six";
                    
                    break;
    
                case '7':
                    output_ += "seven";
                    
                    break;
    
                case '8':
                    output_ += "eight";
                    
                    break;
    
                case '9':
                    output_ += "nine";
                    
                    break;
    
                default:
                    break;
            }
        }
    }
    
    void number_to_english_parser::tens()
    {
        if(remaining() >= 2)
        {            
            const char current_number = consume();
            
            switch(current_number)
            {
                case '0':
                    if(peek() != '0')
                    {
                        add_space_if_needed();
                        ones();
                    }
                    else
                    {
                        consume();
                    }
                    
                    break;
                case '1':
                {
                    add_space_if_needed();
                    
                    const char next_number = consume();
    
                    switch(next_number)
                    {
                        case '0':
                            output_ += "ten";
    
                            break;
    
                        case '1':
                            output_ += "eleven";
    
                            break;
    
                        case '2':
                            output_ += "twelve";
    
                            break;
    
                        case '3':
                            output_ += "thirteen";
    
                            break;
    
                        case '4':
                            output_ += "fourteen";
    
                            break;
    
                        case '5':
                            output_ += "fifteen";
    
                            break;
    
                        case '6':
                            output_ += "sixteen";
    
                            break;
    
                        case '7':
                            output_ += "seventeen";
    
                            break;
    
                        case '8':
                            output_ += "eighteen";
    
                            break;
    
                        case '9':
                            output_ += "nineteen";
    
                            break;
    
                        default:
                            break;
                    }

                    break;
                }
                
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    add_space_if_needed();
                            
                    add_tens_word(current_number);
    
                    if(peek() != '0')
                    {
                        output_ += "-";
                        ones();
                    }
                    else
                    {
                        consume();
                    }
                    
                    break;
    
                default:
                    break;
            }
        }

        if(remaining() == 1)
        {
            ones();
        }
    }
    
    void number_to_english_parser::hundreds()
    {
        if(remaining() >= 3)
        {
            if(peek() != '0')
            {
                add_space_if_needed();
                
                ones();
    
                output_ += " hundred";
            }
            else
            {
                consume();
            }
        }

        tens();
    }
    
    void number_to_english_parser::thousands()
    {
        add_scale_word(4, " thousand");
        
        hundreds();
    }
    
    void number_to_english_parser::millions()
    {
        add_scale_word(7, " million");
        
        thousands();
    }
    
    void number_to_english_parser::billions()
    {
        add_scale_word(10, " billion");
            
        millions();
    }

    number_to_english_parser::number_to_english_parser(long long number)
    {
        if(number < 0 || number > 999'999'999'999)
        {
            throw std::domain_error("Invalid value");
        }
    
        input_ = std::to_string(number);
    }

    string number_to_english_parser::to_english()
    {
        billions();
        
        return output_;
    }

    string in_english(long long number)
    {
        number_to_english_parser parser(number);
        
        return parser.to_english();
    }
}  // namespace say
