#include <array>
#include <string>
#include <vector>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores)
{
    std::vector<int> current_round_down_scores = {};

    int student_scores_size = student_scores.size();
    int i = 0;

    while(true)
    {
        if(i >= student_scores_size)
        {
            break;
        }
        else
        {
            current_round_down_scores.emplace_back(static_cast<int>(student_scores.at(i)));
            
            i = i + 1;
        }
    }
    
    return current_round_down_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores)
{
    int failed_students = 0;

    int student_scores_size = student_scores.size();
    int i = 0;

    while(true)
    {
        if(i >= student_scores_size)
        {
            break;
        }
        else
        {
            if(student_scores.at(i) <= 40)
            {
                failed_students = failed_students + 1;
            }
            
            i = i + 1;
        }
    }
    
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score)
{
    double grade_increment = (highest_score - 41.0) / 4.0;

    int second_grade_boundary = static_cast<int>(std::ceil(41 + grade_increment));
    int third_grade_boundary = static_cast<int>(std::ceil(second_grade_boundary + grade_increment));
    int fourth_grade_boundary = static_cast<int>(std::ceil(third_grade_boundary + grade_increment));
    
    return {41, second_grade_boundary, third_grade_boundary, fourth_grade_boundary};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names)
{
    std::vector<std::string> current_student_ranking = {};

    int student_scores_size = student_scores.size();
    int i = 0;

    while(true)
    {
        if(i >= student_scores_size)
        {
            break;
        }
        else
        {
            current_student_ranking.emplace_back(std::to_string(i + 1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
            
            i = i + 1;
        }
    }
    
    return current_student_ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names)
{
    std::string perfect_score_name = "";

    int student_scores_size = student_scores.size();
    int i = 0;

    while(true)
    {
        if(i >= student_scores_size)
        {
            break;
        }
        else
        {
            if(student_scores.at(i) >= 100)
            {
                perfect_score_name = student_names.at(i);

                break;
            }
            
            i = i + 1;
        }
    }
    
    return perfect_score_name;
}
