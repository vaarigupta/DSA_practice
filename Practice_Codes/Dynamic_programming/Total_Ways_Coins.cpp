#include<iostream>
using namespace std;


int Ways_of_Coins(int *coins, int amt , int n,int *dp)
{

    if(amt==0)
    {
         dp[0] = 1;
        return 1;
    }
    if(dp[amt]!=0)
    {
        return dp[amt];
    }
    int ans =0;
    for(int i=0;i<n;i++)
    {
        if(amt-coins[i]>=0)
        {
             ans += Ways_of_Coins(coins, amt-coins[i],n,dp);
        }

    }

    return dp[amt]=ans;
}
int main()
{
    int dp[100]={0};
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int amt;
    cin>>amt;
    int ans = Ways_of_Coins(coins,amt, n,dp);
    cout<<"Total ways :"<<ans<<endl;

    return 0;
}
