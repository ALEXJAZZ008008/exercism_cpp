#include "secret_handshake.h"

namespace secret_handshake
{
    vector<string> commands(int number)
    {
        vector<string> sequence_of_actions = {};

        if((number >> 0) & 1)
        {
            sequence_of_actions.push_back("wink");
        }

        if((number >> 1) & 1)
        {
            sequence_of_actions.push_back("double blink");
        }

        if((number >> 2) & 1)
        {
            sequence_of_actions.push_back("close your eyes");
        }

        if((number >> 3) & 1)
        {
            sequence_of_actions.push_back("jump");
        }

        if((number >> 4) & 1)
        {
            std::reverse(sequence_of_actions.begin(), sequence_of_actions.end());
        }

        return sequence_of_actions;
    }
}  // namespace secret_handshake
