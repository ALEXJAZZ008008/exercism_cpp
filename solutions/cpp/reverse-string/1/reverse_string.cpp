#include "reverse_string.h"

namespace reverse_string
{
    std::string reverse_string(const std::string& input_string)
    {
        std::string output_string = "";
        
        if (!input_string.empty())
        {
            for(int i = input_string.size() - 1; i >= 0; i--)
            {
                output_string = output_string + input_string.at(i);
            }
        }
        
        return output_string;
    }
}  // namespace reverse_string
