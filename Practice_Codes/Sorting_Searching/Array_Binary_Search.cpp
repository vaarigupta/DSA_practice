#include<iostream>
#define ll signed long long
using namespace std;
ll a[100000000] = {0};
ll binary_Search(ll *a, ll s, ll e, ll key)
{
    ll mid=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
          e = mid -1;
        }
        else
        {
            s = mid +1;
        }
    }
    if(s>e)
    {
        return -1;
    }
}
int main()
{

    ll n,key;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>key;
    cout<<binary_Search(a,0,n-1,key);
    return 0;
}


