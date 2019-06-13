#include<iostream>
using namespace std;
int ladder_ways(int steps, int jump)
{
    if(steps==0)
    {
        return 1;
    }
    if(steps<0)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<=jump;i++)
    {
        ans += ladder_ways(steps-i,jump);
    }
    return ans;
}
int main()
{
int n,k;
cout<<"Enter the steps and jumps:"<<endl;
cin>>n>>k;
cout<<"No of ways : "<<ladder_ways(n,k);
    return 0;
}
