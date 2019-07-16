#include<iostream>
using namespace std;
int maxSum(int *a, int n)
{
    int currS =0, maxS =0;
    for(int i=0;i<n;i++)
    {
        currS += a[i];
        if(currS<0)
        {
            currS = 0;
        }
        maxS = max(maxS, currS);
    }
    return maxS;
}
int main() {
    int t,n,a[100000];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        cout<<maxSum(a,n)<<endl;
    }
	return 0;
}
