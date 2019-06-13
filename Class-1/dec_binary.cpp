#include<iostream>
using namespace std;
int convDecToBin(int n)
{
    int cnt=0 , ans=0, ten_pow=1;
    while(n>0)
    {
//        cnt = n&1;
//        num *= (cnt*(10^i));
//        i++;
//        n = n>>1;


        cnt = n&1;
        ans += (cnt*ten_pow);
        ten_pow *=10;
        n = n>>1;

    }
    return ans;

}
int convBinToDec(int n)
{
int ans = 0, cnt=0, two_pow=1;
while(n!=0)
{
    cnt = n&1;
    ans += (cnt*two_pow);
    two_pow*= 2;
    n >>= 1;
}
return ans;
}
int main()
{
    int n,m;
    cout<<"Decimal :"<<endl;
    cin>>n;
    cout<<"No is : "<<endl;
    cout<<convDecToBin(n)<<endl;
    cout<<"Binary : "<<endl;
    cin>>m;
    cout<<convBinToDec(n);

    return 0;
}
