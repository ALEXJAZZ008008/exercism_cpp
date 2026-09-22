#include "power_of_troy.h"

namespace troy
{
    void give_new_artifact(human& current_human, const std::string& artifact_name)
    {
        current_human.possession = std::make_unique<artifact>(artifact(artifact_name));
    }

    void exchange_artifacts(std::unique_ptr<artifact>& artifact_one, std::unique_ptr<artifact>& artifact_two)
    {
        std::swap(artifact_one, artifact_two);
    }

    void manifest_power (human& current_human, const std::string& power_effect)
    {
        current_human.own_power = std::make_shared<power>(power(power_effect));
    }

    void use_power(human& caster, human& target)
    {
        target.influenced_by = caster.own_power;
    }

    int power_intensity(human& current_human)
    {
        int current_power_intensity = 0;

        if(current_human.own_power != nullptr)
        {
            current_power_intensity = current_human.own_power.use_count();
        }

        return current_power_intensity;
    }
}  // namespace troy
