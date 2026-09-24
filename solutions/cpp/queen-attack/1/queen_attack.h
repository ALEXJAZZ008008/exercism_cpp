#pragma once

#include <stdexcept>
#include <utility>

namespace queen_attack
{
    class chess_board
    {
        private:
            std::pair<int, int> white_ = {};
            std::pair<int, int> black_ = {};

        public:
            chess_board(std::pair<int, int> new_white, std::pair<int, int> new_black)
            {
                if(new_white.first < 0 || new_white.first > 7 || new_white.second < 0 || new_white.second > 7 || new_black.first < 0 || new_black.first > 7 || new_black.second < 0 || new_black.second > 7 || new_white == new_black)
                {
                    throw std::domain_error("Invalid value");
                }

                white_ = new_white;
                black_ = new_black;
            };

            std::pair<int, int> white() const{return white_;};
            std::pair<int, int> black() const{return black_;};

            bool can_attack() const;
    };
}  // namespace queen_attack
