#include<iostream>
using namespace std;

int cellMitosis(int n, int x, int y, int z)
{
    int *dp = new int[n+1];
    dp[0] = dp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i] = min(dp[i-1] +y, dp[(i+1)/2]+ x + z);
        }
        else
        {
            dp[i] = min(dp[i/2] + x, dp[i-1]+y);
        }
    }

    return dp[n];
}
int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cellMitosis(n,x,y,z);
    return 0;

}
