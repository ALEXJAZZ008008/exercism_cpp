#include "grade_school.h"

namespace grade_school
{
    void school::add(std::string name, int grade_number)
    {
        students_[grade_number].push_back(name);

        std::sort(students_[grade_number].begin(), students_[grade_number].end());
    }
    
    std::vector<std::string> school::grade(int grade_number) const
    {
        std::vector<std::string> grade_roster = {};
        
        if(students_.find(grade_number) != students_.end())
        {
            grade_roster = students_.at(grade_number);
        }
        
        return grade_roster;
    }
}  // namespace grade_school
