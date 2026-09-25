#include "allergies.h"

using namespace std;

namespace allergies
{
    bool allergy_test::is_allergic_to(string allergen)
    {
        return allergy_score_ & all_allergens_.at(allergen);
    }
    
    unordered_set<string> allergy_test::get_allergies()
    {
        unordered_set<string> current_allergies = {};
        
        for(map<string, int>::const_iterator i = all_allergens_.begin(); i != all_allergens_.end(); ++i)
        {
            if(is_allergic_to(i->first))
            {
                current_allergies.insert(i->first);
            }
        }

        return current_allergies;
    }
}  // namespace allergies
