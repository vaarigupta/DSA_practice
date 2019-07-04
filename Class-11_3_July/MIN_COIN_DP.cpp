#include<iostream>
using namespace std;
int minCoinTD(int n, int *coins, int m, int *dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp)
}
int minCoinBU(int n, int *coins, int m)
{
    for(int i=0;i<m;i++)
    {
        if(coins[i]<=n)
        {
            for(int j=i;j<m;j++)
            {
                dp[i] = min(dp[n-coins[j]) +1;

            }
        }
    }

}
int main()
{
    return 0;
}
