#include<iostream>
#define ll long long int
using namespace std;
ll optimalGame(ll *coins, int n)
{
   ll dp[35][35] = {0};
   ll ans = 0;
   for(int it=0;it<n;it++)
   {
       for(int i=0,j=it;j<n;i++,j++)
       {
           ll x = ((i+2)<=j)?dp[i+2][j]:0;
           ll y = ((i+1)<=(j-1)) ?dp[i+1][j-1] :0;
           ll z = (i<=(j-2)) ? dp[i][j-2] :0;
           ll op1 = coins[i] + min(x,y);
           ll op2 = coins[j] + min(y,z);
            dp[i][j]  = max(op1,op2);
       }
   }
   return dp[0][n-1];
}
int main()
 {
	int n;
	ll coins[40];
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<optimalGame(coins,n);
	return 0;
}

