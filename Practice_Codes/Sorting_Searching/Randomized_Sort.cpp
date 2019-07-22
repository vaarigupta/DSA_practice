#include<iostream>
#include<ctime>
#include<cstdlib>
#define ll long long
using namespace std;

void shuffleArray(ll *a ,ll s, ll e)
{
    srand(time(NULL));
    ll j=0;
    for(ll i=e;i>s;i--)
    {
        j = rand()%(i+1);
        swap(a[j],a[i]);
    }
}
ll partitionElement(ll *a, ll s, ll e)
{
    ll i= s-1;
    ll pivot = a[e];
    for(ll j=s;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    ll p = i+1;
    swap(a[p],a[e]);
    return p;
}
void randomizedQuick(ll *a, ll s, ll e)
{
    if(s>=e)
    {
        return;
    }
    ll p = partitionElement(a,s,e);
    randomizedQuick(a,s,p-1);
    randomizedQuick(a,p+1,e);

}
ll a[200005];
int main()
{

    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    shuffleArray(a,0,n-1);
    randomizedQuick(a,0,n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}



