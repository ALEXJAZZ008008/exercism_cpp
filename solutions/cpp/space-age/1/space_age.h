#pragma once

#include <cmath>

namespace space_age
{
    class space_age
    {
        private:

        long double age_in_seconds = 0.0;
        
        public:

        space_age()
        {
            
        }

        space_age(int new_age_in_seconds)
        {
            age_in_seconds = static_cast<long double>(new_age_in_seconds);
        }

        space_age(long int new_age_in_seconds)
        {
            age_in_seconds = static_cast<long double>(new_age_in_seconds);
        }

        space_age(double new_age_in_seconds)
        {
            age_in_seconds = static_cast<long double>(new_age_in_seconds);;
        }

        space_age(long double new_age_in_seconds)
        {
            age_in_seconds = new_age_in_seconds;
        }

        long int seconds() const;
        
        double on_earth() const;
        
        double on_mercury() const;
        double on_venus() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;
    };
}  // namespace space_age
