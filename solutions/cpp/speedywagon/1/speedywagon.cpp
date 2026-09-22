#include "speedywagon.h"

namespace speedywagon
{
    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int>* data_array)
    {
        double avg = 0.0;
        
        for (auto element : *data_array)
        {
            avg = avg + element;
        }
        
        avg = avg / data_array->size();
        
        int uv_index = 0;
        
        for (auto element : *data_array)
        {
            if(element > avg)
            {
                uv_index = uv_index + 1;
            }
        }
        
        return uv_index;
    }

    bool connection_check(pillar_men_sensor* sensor_ptr)
    {
        bool connection_check_bool = true;

        if(sensor_ptr == nullptr)
        {
            connection_check_bool = false;
        }

        return connection_check_bool;
    }

    int activity_counter(pillar_men_sensor* sensor_array_ptr, int sensor_array_capacity)
    {
        int total_activity = 0;
        
        int i = 0;

        while(true)
        {
            if(i >= sensor_array_capacity)
            {
                break;
            }
            else
            {
                total_activity = total_activity + (sensor_array_ptr + i)->activity;
                
                i = i + 1;
            }
        }

        return total_activity;
    }

    bool alarm_control(pillar_men_sensor* sensor_array_ptr)
    {
        bool alarm_control_bool = false;

        if(connection_check(sensor_array_ptr))
        {
            if(sensor_array_ptr->activity > 0)
            {
                alarm_control_bool = true;
            }
        }

        return alarm_control_bool;
    }

    bool uv_alarm (pillar_men_sensor* sensor_array_ptr)
    {
        bool uv_alarm_bool = false;

        if(connection_check(sensor_array_ptr))
        {
            int uv_index = uv_light_heuristic(&sensor_array_ptr->data);
            
            if(uv_index > sensor_array_ptr->activity)
            {
                uv_alarm_bool = true;
            }
        }

        return uv_alarm_bool;
    }
}  // namespace speedywagon
