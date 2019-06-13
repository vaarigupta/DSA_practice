#include<iostream>
using namespace std;
int main()
{
    int a[]= {3,3,3,4,4,4,5,5,5,7};
    int b[64] , cnt=0,k=0,ans=0;
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        k=0;
        while(a[i]>0)
        {
        cnt = a[i]&1;
        b[k]= cnt;
        a[i] = a[i]>>1;
        k++;
        }

    }
    int two_p=1;
    for(int i=0;i<64;i++)
    {
        ans += (b[k]%3)*two_p;
        two_p*= 2;
    }
    cout<<ans;
    return 0;
}
