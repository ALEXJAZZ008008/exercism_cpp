#include "triangle.h"

namespace triangle
{
    flavor kind(double side_one, double side_two, double side_three)
    {
        if(!(side_one > 0 && side_two > 0 && side_three > 0) || !(side_one + side_two >= side_three && side_one + side_three >= side_two && side_three + side_two >= side_one))
        {
            throw std::domain_error("Invalid triangle");
        }

        flavor triangle_flavor = {};

        if(side_one + side_two == side_three || side_one + side_three == side_two || side_three + side_two == side_one)
        {
            triangle_flavor = flavor::degenerate;
        }
        else
        {
            if(side_one == side_two && side_one == side_three)
            {
                triangle_flavor = flavor::equilateral;
            }
            else
            {
                if((side_one == side_two && side_one != side_three) || (side_one == side_three && side_one != side_two) || (side_three == side_two && side_three != side_one))
                {
                    triangle_flavor = flavor::isosceles;
                }
                else
                {
                    if(side_one != side_two && side_one != side_three)
                    {
                        triangle_flavor = flavor::scalene;
                    }
                    else
                    {
                        throw std::domain_error("Invalid triangle");
                    }
                }
            }
        }
        
        return triangle_flavor;
    }
}  // namespace triangle
