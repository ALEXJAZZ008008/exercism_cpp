#include "raindrops.h"

namespace raindrops
{
    std::string convert(int raindrop_number)
    {
        std::string raindrop_sound = "";

        bool raindrop_number_is_divisible_by_three = !(raindrop_number % 3);
        bool raindrop_number_is_divisible_by_five = !(raindrop_number % 5);
        bool raindrop_number_is_divisible_by_seven = !(raindrop_number % 7);
        
        if(raindrop_number_is_divisible_by_three)
        {
            raindrop_sound += "Pling";
        }

        if(raindrop_number_is_divisible_by_five)
        {
            raindrop_sound += "Plang";
        }

        if(raindrop_number_is_divisible_by_seven)
        {
            raindrop_sound += "Plong";
        }

        if(!raindrop_number_is_divisible_by_three && !raindrop_number_is_divisible_by_five && !raindrop_number_is_divisible_by_seven)
        {
            raindrop_sound = std::to_string(raindrop_number);
        }

        return raindrop_sound;
    }
}  // namespace raindrops
