#include<iostream>
using namespace std;

void AllIndices(int *a,int i, int n, int m)
{
    ///Base Case
    if(i==n)
    {
        return;
    }
    ///Recursive Case
    if(a[i]==m)
    {
        cout<<i<<" ";
        AllIndices(a,i+1,n,m);
    }
    else
    {
        AllIndices(a,i+1,n,m);
    }
}

int main()
{
    int n,m,a[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    AllIndices(a,0,n,m);
    return 0;
}








