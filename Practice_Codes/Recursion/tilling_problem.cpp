#include<iostream>
#define ll long long int
using namespace std;
ll e=1000000007;

ll no_of_ways(int n,int m,ll dp[])
{ if (n<0) return 0;
  if(n<m) return 1;
  if (dp[n]!=0)return(dp[n]);
  ll ans = no_of_ways(n-1,m,dp) + no_of_ways(n-m,m,dp);
  dp[n]=ans%e;
  return ans;
}
int main()
{
int t;
cin>>t;
while(t--)
{
ll dp[100000]={1};
int n,m;
cin>>n>>m;
for (int i=0;i<m;i++)
{
dp[i]=1;
}
cout<<no_of_ways(n,m,dp)%e<<endl;
}
return 0;
}
