#include "queen_attack.h"

namespace queen_attack
{
    bool chess_board::can_attack() const
    {
        bool queens_can_attack_each_other = false;

        if(white_.first == black_.first || white_.second == black_.second)
        {
            queens_can_attack_each_other = true;
        }

        int i = 1;
        
        while(!queens_can_attack_each_other)
        {
            bool valid_position = false;
            
            std::pair<int, int> attack_position = {black_.first - i, black_.second - i};

            if(attack_position.first >= 0 && attack_position.first <= 7 && attack_position.second >= 0 && attack_position.second <= 7)
            {
                valid_position = true;
                
                if(white_.first == attack_position.first && white_.second == attack_position.second)
                {
                    queens_can_attack_each_other = true;

                    break;
                }
            }

            attack_position = {black_.first + i, black_.second - i};

            if(attack_position.first >= 0 && attack_position.first <= 7 && attack_position.second >= 0 && attack_position.second <= 7)
            {
                valid_position = true;
                
                if(white_.first == attack_position.first && white_.second == attack_position.second)
                {
                    queens_can_attack_each_other = true;

                    break;
                }
            }

            attack_position = {black_.first - i, black_.second + i};

            if(attack_position.first >= 0 && attack_position.first <= 7 && attack_position.second >= 0 && attack_position.second <= 7)
            {
                valid_position = true;
                
                if(white_.first == attack_position.first && white_.second == attack_position.second)
                {
                    queens_can_attack_each_other = true;

                    break;
                }
            }

            attack_position = {black_.first + i, black_.second + i};

            if(attack_position.first >= 0 && attack_position.first <= 7 && attack_position.second >= 0 && attack_position.second <= 7)
            {
                valid_position = true;
                
                if(white_.first == attack_position.first && white_.second == attack_position.second)
                {
                    queens_can_attack_each_other = true;

                    break;
                }
            }

            if(!valid_position)
            {
                break;
            }
            
            ++i;
        }
        
        return queens_can_attack_each_other;
    }
}  // namespace queen_attack
