#include<iostream>
using namespace std;
int ways(int n, int k)
{
    int ans =0;
    if(n==1 || n==0)
    {
        return 1;
    }
    if(n<1)
    {
        return 0;
    }

    for(int i=1;i<=k;i++)
    {
        ans += ways(n-i,k);
    }
}
int main()
{
    int n,k;
    cout<<"Enter the no of steps and jumps : "<<endl;
    cin>>n>>k;
    cout<<"No of ways : "<<ways(n,k);
    return 0;
}


