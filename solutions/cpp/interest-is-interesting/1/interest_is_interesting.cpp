// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance)
{
    double current_interest_rate = 0.0;

    if(balance < 0.0)
    {
        current_interest_rate = 3.213;
    }
    else
    {
        if(balance < 1'000.0)
        {
            current_interest_rate = 0.5;
        }
        else
        {
            if(balance < 5'000.0)
            {
                current_interest_rate = 1.621;
            }
            else
            {
                current_interest_rate = 2.475;
            }
        }
    }
    
    return current_interest_rate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance)
{
    return (balance / 100.0) * interest_rate(balance);
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance)
{
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance)
{
    int current_years_until_desired_balance = 0;
    double current_balance = balance;

    while(true)
    {
        if(current_balance >= target_balance)
        {
            break;
        }
        else
        {
            current_balance = annual_balance_update(current_balance);
            current_years_until_desired_balance = current_years_until_desired_balance + 1;
        }
    }
    
    return current_years_until_desired_balance;
}
