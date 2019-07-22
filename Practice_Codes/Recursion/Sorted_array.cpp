#include<iostream>
#define ll long long
using namespace std;
bool sortedArray(ll *a , int n)
{
    if(n==1)
    {
        return true;
    }
    if(a[0]<=a[1] && sortedArray(a+1,n-1))
    {
        return true;
    }
    return false;
}
int main()
{
   ll a[1005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(sortedArray(a,n))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}

