#include<iostream>
using namespace std;
int ans = 0;
int dp[1000];
int maxWeight(int *val , int *wt ,int i, int n, int maxWt)
{
    if(maxWt==0)
    {
        return 0;
    }
    if(wt[i]<maxWt)
    {
        ans += val[i];
    }

}
int main()
{
    int val[100] , wt[100] , n,maxWt;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>wt[i];
    }
    cin>>maxWt;
    cout<<maxWeight(val,wt,n, maxWt);

    return 0;
}

