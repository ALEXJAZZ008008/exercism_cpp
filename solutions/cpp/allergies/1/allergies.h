#pragma once

#include <string>
#include <map>
#include <unordered_set>

namespace allergies
{
    class allergy_test
    {
        private:
            int allergy_score_ = 0;
            const std::map<std::string, int> all_allergens_ = {{"eggs", 1}, {"peanuts", 2}, {"shellfish", 4}, {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32}, {"pollen", 64}, {"cats", 128}};
        
        public:
            explicit allergy_test(int new_allery_score) : allergy_score_(new_allery_score){}

            bool is_allergic_to(std::string allergen);
            std::unordered_set<std::string> get_allergies();
    };
}  // namespace allergies
