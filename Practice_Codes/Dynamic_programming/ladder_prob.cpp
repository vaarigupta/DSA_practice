#include<iostream>
#include<algorithm>
using namespace std;

/// time - O(k^n)
int Ways(int n, int k)
{
    if(n==0)
    {
        return 1;
    }
    if(n < 0)
    {
        return 0;
    }
    int ans =0;
    for(int i=1;i<=k;i++)
    {
         ans += Ways(n-i,k);
    }
    return ans;
}
/// time - O(nk)
int WaysTD(int n, int k, int *dp)
{
    if(n==0)
    {
        dp[0] = 1;
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!= -1)
    {
        return dp[n];
    }
    int ans = 0;
    for(int i=1;i<=k;i++)
    {
        ans += WaysTD(n-i,k,dp);
        dp[n] = ans;
    }
    return dp[n];
}
/// time - O(nk)
int WaysBU(int n, int k)
{
    int *dp = new int[n];
    dp[0] = 1;
    for(int step=1;step<=n;step++)
    {
        dp[step] = 0;
        for(int j=1;j<=k;j++)
        {
            if(step-j>=0)
            {
                dp[step] += dp[step-j];
            }

        }
    }
    return dp[n];
}


///???? some logical error
/// time - O(n)
int WaysOptimized(int n, int k)
{
    int *dp = new int[n];
    dp[0] = 1;
    dp[1] = 1;
    for(int step=2;step<=n;step++)
    {
        int ans = 2*dp[step-1];
        dp[step] = ans;
        if(step-k>0)
        {
            dp[step] -= dp[step-k];
        }

    }
    return dp[n];
}
int main()
{
    int n,k,dp[100];
    cin>>n>>k;
    fill(dp,dp+n+1,-1);
    cout<<Ways(n,k)<<endl;
    cout<<WaysTD(n,k,dp)<<endl;
    cout<<WaysBU(n,k)<<endl;
    cout<<WaysOptimized(n,k)<<endl;

    return 0;
}
