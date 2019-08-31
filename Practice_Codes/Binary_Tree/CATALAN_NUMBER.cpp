#include<iostream>
#define ll long long int
using namespace std;
ll dp[101] = {0};
ll catalanNo(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    ll ans =0;
    for(int i=1;i<=n;i++)
    {
        ans += catalanNo(i-1)*catalanNo(n-i);
    }
    dp[n] = ans;
    return ans;
}

ll factNo(int n)
{
    ll dp[101];
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]*i;
    }
    return dp[n];
}
ll catalanNoFormula(int n)
{
    ll fact1 = factNo(n);
    ll fact2 = factNo(2*n);
    ll ans = fact2/(fact1*fact1*(n+1));
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
         cout<<catalanNoFormula(i)<<", ";
    }


    return 0;
}




/*

10
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796,
*/









