#pragma once

#include <stdexcept>

namespace triangle
{
    enum class flavor
    {
        equilateral,
        isosceles,
        scalene,
        degenerate
    };

    flavor kind(double side_one, double side_two, double side_three);
}  // namespace triangle
