#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace grade_school
{
    class school
    {
        private:
            std::map<int, std::vector<std::string>> students_ = {};

        public:
            const std::map<int, std::vector<std::string>>& roster() const {return students_;};

            void add(std::string name, int grade_number);
            std::vector<std::string> grade(int grade_number) const;
    };
}  // namespace grade_school
