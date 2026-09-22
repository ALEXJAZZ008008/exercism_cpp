#pragma once

#include <string>
#include <vector>

namespace speedywagon
{
    struct pillar_men_sensor
    {
        int activity = 0;
        std::string location = "";
        std::vector<int> data = {};
    };
    
    int uv_light_heuristic(std::vector<int>* data_array);
    bool connection_check(pillar_men_sensor* sensor_ptr);
    int activity_counter(pillar_men_sensor* sensor_array_ptr, int sensor_array_capacity);
    bool alarm_control(pillar_men_sensor* sensor_array_ptr);
    bool uv_alarm (pillar_men_sensor* sensor_array_ptr);
}  // namespace speedywagon
