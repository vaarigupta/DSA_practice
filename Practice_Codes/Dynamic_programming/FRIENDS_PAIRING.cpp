#include<iostream>
#include<cstring>
#define ll long long int
#define mod 1000000007
using namespace std;

ll friendsPairing(int n,ll *dp)
{
    if(n<=0)
    {
        dp[0] = 1;
        return 1;
    }
    if(n==1)
    {
        dp[1] = 1;
        return 1;
    }
    ///computed so only return that value - no need for recomputation
    if(dp[n]!=-1)
    {
        return dp[n];
    }
     ll ans =  (friendsPairing(n-1,dp) + (n-1)*friendsPairing(n-2,dp));
    return dp[n] = ans%mod;
}

ll friendsPairingBU(int n)
{
    ll *dp = new ll[n+1]{0};
    dp[0] =1;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = ((dp[i-1] + (i-1)*dp[i-2]))%mod;
        //cout<<i<<" - "<<dp[i]<<endl;
    }
    return dp[n];
}
int main()
 {
	int t, n;
	ll dp[105];
	memset(dp,-1,sizeof(dp));
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<friendsPairing(n,dp)<<endl;
	}
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<friendsPairingBU(n)<<endl;
	}
	return 0;
}
