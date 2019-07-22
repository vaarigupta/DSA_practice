#include<iostream>
#define ll long long
using namespace std;
ll tillingWays(ll n ,  ll m)
{
    if(n==0 or n<m)
    {
        return 1;
    }
     ll x = tillingWays(n-1,m);
     ll y = tillingWays(n-m,m);
     return 1+ x+y;
}
int main()
{
    ll t;
    ll n, m;
    while(t--)
    {
        cin>>n>>m;
        cout<<tillingWays(n,m)<<endl;
    }

    return 0;
}

