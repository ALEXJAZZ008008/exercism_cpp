#include <string>
#include <vector>

namespace election
{
    // The election result struct is already created for you:
    struct ElectionResult
    {
        // Name of the candidate
        std::string name = "";
        
        // Number of votes the candidate has
        int votes = 0;
    };
    
    int vote_count(const ElectionResult& current_election_result)
    {
        return current_election_result.votes;
    }
    
    void increment_vote_count(ElectionResult& current_election_result, int vote_increment)
    {
        current_election_result.votes = current_election_result.votes + vote_increment;
    }
    
    ElectionResult& determine_result(std::vector<ElectionResult>& final_count)
    {
        ElectionResult* result = &final_count.at(0);

        int final_count_size = final_count.size();
        int i = 1;

        while(true)
        {
            if(i >= final_count_size)
            {
                break;
            }
            else
            {                
                if(final_count.at(i).votes > result->votes)
                {
                    result = &final_count.at(i);
                }

                i = i + 1;
            }
        }

        result->name = "President " + result->name;

        return *result;
    }

}  // namespace election
