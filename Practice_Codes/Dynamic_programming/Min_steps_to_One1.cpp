#include<iostream>
#include<algorithm>
using namespace std;
int dp[100000];

///top - down dp
int minSteps(int n)
{
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if(n<=1)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
        /// whenever we require any previous value then we do not need to compute
        /// hence our time is saved as no need to recompute
    }
    if(n%3==0) op1 = 1 + minSteps(n/3);
    if(n%2==0) op2 =  1 + minSteps(n/2);
    op3 = 1 + minSteps(n-1);

    ///whenever we encounter new value, we compute and save them in dp array
    dp[n] = min(op1,min(op2,op3));
   return dp[n];
}
///bottom up approach
int minStepsBU(int n)
{

    dp[0] = dp[1] = 0;
    dp[2] = dp[3]= 1;
    //int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    for(int i = 4;i<=n;i++)
    {
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if(i%3 == 0) op1 = 1 + dp[i/3];
    if(i%2 == 0) op2 =  1 + dp[i/2];
    op3 = 1 + dp[i-1];
        dp[i] = min(op1,min(op2,op3));
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    fill(dp,dp+n+1,-1);
    cout<<"Minimum steps to One : "<<minSteps(n)<<endl;
    fill(dp,dp+n+1,-1);
    cout<<"Minimum steps to One : "<<minStepsBU(n)<<endl;

    return 0;
}



//You should reinitialise op1 , op2, op3 as INT_MAX in every iteration of the for loop.
//Change it to this.
//for(int i = 4;i<=n;i++)
//{
//int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
//if(i%3 == 0) op1 = 1 + dp[i/3];
//if(i%2 == 0) op2 = 1 + dp[i/2];
//op3 = 1 + dp[i-1];
