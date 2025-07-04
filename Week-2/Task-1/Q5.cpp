#include<bits/stdc++.h>

using namespace std;

#define double long double
/*
Note: a) The Stock price is not recurrent because there is no state to which the chain returns with absolute certainty
      b) There is no Stationary state because the probability is same for all states.
*/

int32_t main()
{
    int ticks = 2160;
    int target = 13000;
    // extrapolated by 100x so that tick size=1 (and not 0.01)

    vector<vector<double>> dp(ticks+1, vector<double>(target+1));

    dp[0][12000] = 1.0;

    for(int state=1;state<=ticks;state++)
    {
        for(int cost=1;cost<=target;cost++)
        {
            // plus 1 tick
            dp[state][cost] += dp[state-1][cost-1]*0.1;
            // remains same
            dp[state][cost] += dp[state-1][cost]*0.85;
            // minus 1 tick
            if(cost+1<=target)
                dp[state][cost] += dp[state-1][cost+1]*0.05;
        }
    }

    // for(int i=0;i<=ticks;i++)
    // {
    //     for(int j=12000;j<=13000;j++)
    //         cout<<dp[i][j]<<" ";
    //     nl;
    // }
    // nl;nl;

    double prob = 0.0;

    for(int i=1;i<=ticks;i++)
    {
        prob += dp[i][13000];
    }
    cout<<"Probability for stock to reach 130INR in 2160 ticks = ";
    cout<<prob<<endl;
    
    return 0;
}
