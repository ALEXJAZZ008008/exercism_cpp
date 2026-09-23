#include "space_age.h"

namespace space_age
{
    long int space_age::seconds() const
    {
        return static_cast<long int>(std::floor(age_in_seconds));
    }

    double space_age::on_earth() const
    {
        return (((age_in_seconds / 60.0) / 60.0) / 24.0) / 365.25;
    }
    
    double space_age::on_mercury() const
    {
        return on_earth() / 0.2408467;
    }
    
    double space_age::on_venus() const
    {
        return on_earth() / 0.61519726;
    }
    
    double space_age::on_mars() const
    {
        return on_earth() / 1.8808158;
    }
    
    double space_age::on_jupiter() const
    {
        return on_earth() / 11.862615;
    }
    
    double space_age::on_saturn() const
    {
        return on_earth() / 29.447498;
    }
    
    double space_age::on_uranus() const
    {
        return on_earth() / 84.016846;
    }
    
    double space_age::on_neptune() const
    {
        return on_earth() / 164.79132;
    }
}  // namespace space_age
