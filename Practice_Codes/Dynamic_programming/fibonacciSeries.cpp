#include<iostream>
using namespace std;
int memo[100000];
int fibTD(int n)
{

    if(n==0 || n==1 )
    {
        return n;
    }
    if(memo[n]!=-1)
    {

        ///Already computed before and registerd in DP so we can fetch it in O(1) time
        return memo[n];
    }
    int ans = fibTD(n-1) + fibTD(n-2);
    memo[n] = ans;/// for new computations, we register them in the array
    return ans;

}
 int dp[100000]= {0};
int fibBU(int n)
{

    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
     for(int i=0;i<=100000;i++)
     {
         memo[i] = -1;
     }
    cout<<n<<"th fibonacci no : "<<fibTD(n)<<endl;
    cout<<n<<"th fibonacci no : "<<fibBU(n)<<endl;
    return 0;
}
