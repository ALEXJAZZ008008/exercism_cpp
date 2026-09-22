#include "lasagna_master.h"

namespace lasagna_master
{
    int preparationTime(std::vector<std::string> layers, int preperation_time_per_layer)
    {
        return layers.size() * preperation_time_per_layer;
    }

    amount quantities (std::vector<std::string> layers)
    {
        amount amount_needed = {};

        int layers_size = layers.size();
        int i = 0;

        while(true)
        {
            if(i >= layers_size)
            {
                break;
            }
            else
            {
                std::string layers_at_i = layers.at(i);

                if(layers_at_i == "noodles")
                {
                    amount_needed.noodles = amount_needed.noodles + 50;
                }
                else
                {
                    if(layers_at_i == "sauce")
                    {
                        amount_needed.sauce = amount_needed.sauce + 0.2;
                    }
                }
            }

            i = i + 1;
        }

        return amount_needed;
    }

    void addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient)
    {
        myList.at(myList.size() - 1) = secretIngredient;
    }
    
    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList)
    {
        myList.at(myList.size() - 1) = friendsList.at(friendsList.size() - 1);
    }

    std::vector<double> scaleRecipe(std::vector<double> quantities, int number_of_portions)
    {
        std::vector<double> scaled_recipe = {};

        int quantities_size = quantities.size();
        int i = 0;

        while(true)
        {
            if(i >= quantities_size)
            {
                break;
            }
            else
            {
                scaled_recipe.push_back((quantities.at(i) / 2.0) * number_of_portions);
            }

            i = i + 1;
        }
        
        return scaled_recipe;
    }
}  // namespace lasagna_master
