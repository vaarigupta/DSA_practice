#include<iostream>
#define ll long long
using namespace std;
int lastIndex(ll *a , int n, ll key)
{
    if(n<0)
    {
        return -1;
    }
    if(a[n]==key)
    {
        return n;
    }
    return lastIndex(a,n-1,key);


}
int main()
{
   ll a[1005];
   ll key;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>key;
    cout<<lastIndex(a,n-1,key)<<endl;
    return 0;
}


