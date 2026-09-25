#include "sum_of_multiples.h"

#include <cstddef>

using namespace std;

namespace sum_of_multiples
{
    vector<int> get_multiples(int item_level, int stage_level)
    {
        vector<int> current_item_level_multiples = {};

        int i = 1;
        
        while(true)
        {
            int current_item_level_multiple = item_level * i++;

            if(current_item_level_multiple >= stage_level)
            {
                break;
            }

            current_item_level_multiples.push_back(current_item_level_multiple);
        }

        return current_item_level_multiples;
    }
    
    int to(vector<int> item_levels, int stage_level)
    {
        int energy_points = 0;

        vector<vector<int>> item_level_multiples = {};
        
        for(size_t i = 0; i < item_levels.size(); ++i)
        {
            item_level_multiples.push_back(get_multiples(item_levels.at(i), stage_level));
        }

        vector<int> item_level_multiples_combined_without_duplicates = {};

        for(size_t i = 0; i < item_level_multiples.size(); ++i)
        {
            for(size_t j = 0; j < item_level_multiples.at(i).size(); ++j)
            {
                bool exists = false;
                
                for(size_t k = 0; k < item_level_multiples_combined_without_duplicates.size(); ++k)
                {
                    if(item_level_multiples.at(i).at(j) == item_level_multiples_combined_without_duplicates.at(k))
                    {
                        exists = true;

                        break;
                    }
                }

                if(!exists)
                {
                    item_level_multiples_combined_without_duplicates.push_back(item_level_multiples.at(i).at(j));
                }
            }
        }

        for(size_t i = 0; i < item_level_multiples_combined_without_duplicates.size(); ++i)
        {
            energy_points += item_level_multiples_combined_without_duplicates.at(i);
        }

        return energy_points;
    }
}  // namespace sum_of_multiples
