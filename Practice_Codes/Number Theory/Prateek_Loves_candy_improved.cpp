#include<iostream>
#define ll long long
using namespace std;
ll p[1000010]={0};
ll a[1000010];

void primeSieve()
{
    p[0] =p[1] = 0;
    for(int i=2;i<1000000;i++)
    {
        if(p[i])
        {
            for(int j=(2*i);j<=1000000;j+=i)
            {
                p[j]=0;
            }
        }
    }
}

int main()
{
    int t,n;
    cin>>t;
    fill(p,p+1000000,1);
    primeSieve();
    int k=1;
    a[0]=2;
    for(int i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            a[k++] = i;
        }
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    }
    return 0;
}
