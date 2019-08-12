#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/// time - O()
int min_coins(int *coins, int n, int amt)
{
    if(amt==0)
    {
        return 0;
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amt-coins[i]>=0)
        {
            int smallAns = min_coins(coins,n,amt-coins[i]);
            if(smallAns!=INT_MAX)
            {
                 ans = min(ans,smallAns+1);
            }

        }

    }
    return ans;

}
/// time - O()
int min_coinsTD(int *coins, int n, int amt, int *dp)
{
    if(amt==0)
    {
        dp[0] = 0;
        return 0;
    }
    if(dp[amt]!=INT_MAX)
    {
        return dp[amt];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amt-coins[i]>=0)
        {
            int smallAns = min_coinsTD(coins,n,amt-coins[i],dp);
            if(smallAns!=INT_MAX)
            {
                ans = min(ans,smallAns+1);
                dp[amt] = ans;

            }
        }

    }
    return dp[amt];

}
/// time - O()
int min_coinsBU(int *coins, int n, int amt)
{
    int *dp = new int[amt+1];

    for(int i=0;i<=amt;i++)
    {
        dp[i] = INT_MAX;
    }
        dp[0] = 0;
    ///fill(dp,dp+amt+1,INT_MAX);
    for(int rupee=1;rupee<=amt;rupee++)
    {
        for(int i=0;i<n;i++)
        {
            if(rupee>=coins[i])
            {
            int smallAns = dp[rupee-coins[i]];
            if(smallAns!=INT_MAX)
            {
                 dp[rupee] = min(dp[rupee],smallAns+1);
            }
            }
        }
    }
    return dp[amt];
}

int main()
{
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int amt = 15;
    int dp[100];
    for(int i=0;i<=100;i++)
    {
        dp[i] = INT_MAX;
    }
    //cout<<min_coinsBU(coins,n,amt)<<endl;
    cout<<min_coinsTD(coins,n,amt,dp)<<endl;


    return 0;
}

