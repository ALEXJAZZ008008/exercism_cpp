#pragma once

#include <string>

namespace star_map
{
    enum class System
    {
        Sol,
        BetaHydri,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven
{
    class Vessel
    {
        public:

        std::string name = "";
        int generation = 0;
        
        star_map::System current_system = star_map::System::Sol;

        int busters = 0;

        Vessel(std::string new_name, int new_generation)
        {
            name = new_name;
            generation = new_generation;
        }

        Vessel(std::string new_name, int new_generation, star_map::System new_current_system)
        {
            name = new_name;
            generation = new_generation;
            current_system = new_current_system;
        }

        Vessel replicate(std::string new_name);
        
        void make_buster();
        bool shoot_buster();
    };

    std::string get_older_bob(Vessel vessel_one, Vessel vessel_two);
    bool in_the_same_system(Vessel vessel_one, Vessel vessel_two);
}
