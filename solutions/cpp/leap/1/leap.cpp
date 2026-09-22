#include "leap.h"

namespace leap
{
    bool is_leap_year(int year)
    {
        bool is_leep_year_bool = false;

        if(!(year % 4))
        {
            if(!(year % 100))
            {
                if(!(year % 400))
                {
                    is_leep_year_bool = true;
                }
            }
            else
            {
                is_leep_year_bool = true;
            }
        }

        return is_leep_year_bool;
    }
}  // namespace leap
