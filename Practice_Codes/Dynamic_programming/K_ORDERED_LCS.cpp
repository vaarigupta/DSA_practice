#include<iostream>
#include<cstring>
#define ll long long
#define F(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

ll dp[2005][2005][8];
ll n,m,k;
ll a[2005] , b[2005];
ll k_ordered_lcs(ll i, ll j, ll k)
{
    if(i==n || j==m)
    {
        return 0;
    }

     if(dp[i][j][k]!= -1)
     {
         return dp[i][j][k];
     }
      ll res =0;
    if(a[i]==b[j])
    {
        ///we are not changing any char
        res = 1 + k_ordered_lcs(i+1,j+1, k);
    }
    else
    {
        if(k>0)
        {
            ///one char is changed then it becomes like the prev condition
            res = 1 + k_ordered_lcs(i+1,j+1,k-1);
        }
        res = max(res,k_ordered_lcs(i,j+1,k));
        res = max(res, k_ordered_lcs(i+1,j,k));


    }
    return dp[i][j][k] = res;
}

int main()
{

   memset(dp,-1,sizeof(dp));
   cin>>n>>m>>k;
   F(i,0,n)
   {
      cin>>a[i];
   }
   F(i,0,m)
   {
      cin>>b[i];
   }

   cout<<k_ordered_lcs(0,0,k);
    return 0;

}




