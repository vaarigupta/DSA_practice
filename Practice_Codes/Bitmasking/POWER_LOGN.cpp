#include<iostream>
#define ll long long
using namespace std;
ll power(int x, int n)
{
	ll ans = 1;
	ll a = x;
	ll b = n;
	while(b>0)
	{
		if(b&1)
		{
			ans *= a;

		}
        a *= a;
		b >>= 1;
	}
	return ans;
}
int main() {
	int x, n;
	cin>>x>>n;
	cout<<power(x,n);
	return 0;
}
