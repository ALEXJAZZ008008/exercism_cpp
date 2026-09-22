namespace hellmath
{
    enum class AccountStatus
    {
        troll,
        guest,
        user,
        mod
    };
    
    enum class Action
    {
        read,
        write,
        remove
    };
    
    bool display_post(AccountStatus poster_status, AccountStatus viewer_status)
    {
        bool display_post_bool = true;
        
        switch(poster_status)
        {
            case AccountStatus::troll:
                switch(viewer_status)
                {
                    case AccountStatus::guest:
                    case AccountStatus::user:
                    case AccountStatus::mod:
                        display_post_bool = false;

                        break;

                    default:
                        break;
                }

                break;
            
            case AccountStatus::guest:
                display_post_bool = false;

                break;

            default:
                break;
        }

        return display_post_bool;
    }
    
    bool permission_check(Action user_action, AccountStatus user_status)
    {
        bool permission_bool = true;
        
        switch(user_action)
        {
            case Action::write:
                switch(user_status)
                {
                    case AccountStatus::guest:
                        permission_bool = false;

                        break;

                    default:
                        break;
                }

                break;
            
            case Action::remove:
                switch(user_status)
                {
                    case AccountStatus::troll:
                    case AccountStatus::guest:
                    case AccountStatus::user:
                        permission_bool = false;

                        break;

                    default:
                        break;
                }

            default:
                break;
        }

        return permission_bool;
    }
    
    bool valid_player_combination (AccountStatus player_one_status, AccountStatus player_two_status)
    {
        bool valid_player_combination_bool = false;
        
        switch(player_one_status)
        {
            case AccountStatus::troll:
                switch(player_two_status)
                {
                    case AccountStatus::troll:
                        valid_player_combination_bool = true;

                        break;

                    default:
                        break;
                }
                
                break;
            
            case AccountStatus::user:
            case AccountStatus::mod:
                switch(player_two_status)
                {
                    case AccountStatus::user:
                    case AccountStatus::mod:
                        valid_player_combination_bool = true;

                        break;

                    default:
                        break;
                }

                break;

            default:
                break;
        }

        return valid_player_combination_bool;
    }
    
    bool has_priority(AccountStatus player_one_status, AccountStatus player_two_status)
    {
        bool has_priority_bool = false;
        
        switch(player_one_status)
        {
            case AccountStatus::guest:
                switch(player_two_status)
                {
                    case AccountStatus::troll:
                        has_priority_bool = true;

                        break;

                    default:
                        break;
                }
                
                break;
            
            case AccountStatus::user:
                switch(player_two_status)
                {
                    case AccountStatus::troll:
                    case AccountStatus::guest:
                        has_priority_bool = true;

                        break;

                    default:
                        break;
                }
                
                break;
            
            case AccountStatus::mod:
                switch(player_two_status)
                {
                    case AccountStatus::troll:
                    case AccountStatus::guest:
                    case AccountStatus::user:
                        has_priority_bool = true;

                        break;

                    default:
                        break;
                }

                break;

            default:
                break;
        }

        return has_priority_bool;
    }
}  // namespace hellmath
