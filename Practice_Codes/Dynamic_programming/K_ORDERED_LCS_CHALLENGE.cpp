#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
ll n,m;
ll a[2005] , b[2005];
ll dp[2005][2005][8];
ll k_ordered_lcs(ll i, ll j, ll k)
{
    if(i==n || j==m)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    ll ans = 0;
    if(a[i]==b[j])
    {
        ans = 1 + k_ordered_lcs(i+1,j+1,k);
    }
    else
    {
        if(k>0)
        {
             ans = 1 + k_ordered_lcs(i+1,j+1,k-1) ;
        }
        ans = max(ans,k_ordered_lcs(i+1,j,k));
        ans  = max(ans,k_ordered_lcs(i,j+1,k));

    }
    return dp[i][j][k]=ans;

}
int main()
{
    ll k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    f(i,1,n)
    {
        cin>>a[i];
    }
    f(i,1,m)
    {
        cin>>b[i];
    }
    cout<<k_ordered_lcs(1,1,k);
	return 0;
}


