#pragma once

#include <string>
#include <memory>
#include <utility>

namespace troy
{
    class artifact
    {
        public:
        
        std::string name = "";

        artifact()
        {
            
        }
        
        artifact(std::string new_name)
        {
            name = new_name;
        }
    };
    
    class power
    {
        public:
        
        std::string effect = "";

        power()
        {
            
        }
        
        power(std::string new_effect)
        {
            effect = new_effect;
        }
    };

    class human
    {
        public:

        std::unique_ptr<artifact> possession = nullptr;

        std::shared_ptr<power> own_power = nullptr;
        std::shared_ptr<power> influenced_by = nullptr;
    };

    void give_new_artifact(human& current_human, const std::string& artifact_name);
    void exchange_artifacts(std::unique_ptr<artifact>& artifact_one, std::unique_ptr<artifact>& artifact_two);
    
    void manifest_power (human& current_human, const std::string& power_effect);
    void use_power(human& caster, human& target);
    int power_intensity(human& current_human);
}  // namespace troy
