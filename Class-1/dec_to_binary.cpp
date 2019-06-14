#include<iostream>
using namespace std;
int dec_to_bin(int n)
{
    int ans=0,ten_pow=1;
    while(n>0)
    {
        ans += ((n&1)*ten_pow);
        ten_pow*= 10;
        n >>= 1;
    }
    return ans;

}

int bin_to_dec(int n)
{
    int ans=0,two_pow=1;
    while(n>0)
    {
        ans += ((n%10)*two_pow);
        two_pow*= 2;
        n /= 10;
    }
    return ans;

}
int main()
{
    int n,m;
    cout<<"Enter the decimal form : "<<endl;
    cin>>n;
    cout<<"Binary form : "<<dec_to_bin(n)<<endl;
    cout<<"Enter the binary form : "<<endl;
    cin>>m;
    cout<<"Decimal form : "<<bin_to_dec(m)<<endl;

    return 0;
}

