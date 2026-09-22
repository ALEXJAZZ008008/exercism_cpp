#include "doctor_data.h"

namespace heaven
{
    Vessel Vessel::replicate(std::string new_name)
    {
        Vessel new_vessel = Vessel(new_name, this->generation + 1);
    
        return new_vessel;
    }
    
    void Vessel::make_buster()
    {
        this->busters = 1;
    }
    
    bool Vessel::shoot_buster()
    {
        bool shoot_buster_bool = false;
        
        if(this->busters == 1)
        {
            shoot_buster_bool = true;

            this->busters = 0;
        }
    
        return shoot_buster_bool;
    }
    
    std::string get_older_bob(Vessel vessel_one, Vessel vessel_two)
    {
        std::string older_bob = vessel_one.name;

        if(vessel_two.generation < vessel_one.generation)
        {
            older_bob = vessel_two.name;
        }

        return older_bob;
    }
    
    bool in_the_same_system(Vessel vessel_one, Vessel vessel_two)
    {
        bool in_the_same_system_bool = true;

        if(vessel_one.current_system != vessel_two.current_system)
        {
            in_the_same_system_bool = false;
        }

        return in_the_same_system_bool;
    }
}
