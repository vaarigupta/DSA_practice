#include<iostream>
using namespace std;
int main()
{
    int n , cnt=0;
    cin>>n;
    while(n>0)
    {
       cnt += (n&1);
       n = n>>1;
    }
    cout<<cnt;
    return 0;
}
