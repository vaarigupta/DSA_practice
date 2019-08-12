#include<iostream>
using namespace std;

///rec solution
int Ways_of_Coins(int *coins, int amt , int n)
{
   if(amt==0)
   {
       return 1;
   }

   int ans =0;
   for(int i=0;i<n;i++)
   {
       if(amt-coins[i]>=0)
       {
         ans += Ways_of_Coins(coins,amt-coins[i],n);
       }

   }
   return ans;

}

///Top down dp
int Ways_of_CoinsTD(int *coins, int amt , int n, int *dp)
{
   if(amt==0)
   {
       dp[0] =1;
       return 1;
   }

   int ans =0;
   ///if the value already computed then we will use it instead of computing it again
   if(dp[amt]!=0)
   {
       return dp[amt];
   }
   for(int i=0;i<n;i++)
   {
       if(amt-coins[i]>=0)
       {
         ans += Ways_of_Coins(coins,amt-coins[i],n);
       }

   }
   ///if value is not computed then, we will compute and store it in dp array
   dp[amt] = ans;
   return ans;

}

///Bottom Up dp
int Ways_of_CoinsBU(int *coins, int amt , int n)
{
  int dp[100] = {0};
  dp[0] = 1;
  for(int i=1;i<=amt;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(i-coins[j]>=0)
          {
              dp[i] += dp[i-coins[j]];
          }

      }
  }
  return dp[amt];
}
int main()
{
    int dp[100]={0};
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int amt;
    cin>>amt;
    int ans = Ways_of_Coins(coins,amt, n);
    cout<<"Total ways :"<<ans<<endl;
    ans = Ways_of_CoinsTD(coins,amt, n,dp);
    cout<<"Total ways :"<<ans<<endl;
    ans = Ways_of_CoinsBU(coins,amt, n);
    cout<<"Total ways :"<<ans<<endl;

    return 0;
}

