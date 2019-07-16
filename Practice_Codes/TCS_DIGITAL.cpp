#include<iostream>
using namespace std;
double pn(int n, double x, double *dp)
{
    if(n==0)
    {
        dp[0] = 1;
        return dp[0];
    }
    if(n==1)
    {
        dp[1] = x;
        return dp[1];
    }

    dp[n]= (((2*n)+1)*x*pn(n-1,x,dp) - n*pn(n-2,x,dp))/(n+1);
    return dp[n];
}
int main()
{
    int n;
    double x;
    double dp[100000] = {0.00};
    cin>>n>>x;
    double ans = pn(n,x,dp);
    cout.precision(4);
    cout<<ans<<" ";

    return 0;
}

