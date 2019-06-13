#include<iostream>
using namespace std;

///Time - O() ??
int power(int a, int n)
{
    ///base case
    if(n==0)
    {
        return 1;
    }

    ///rec case
    int subProb = power(a,n/2);
    subProb = subProb*subProb;
    if(n&1)
    {
        ///for odd powers
        return a*subProb;
    }
    ///even powers
    return subProb;
}

///Time - o(log(n))
///space - o(1)
int fastPower(int a,int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1)
        {
            ans *=a;
        }
        a= a*a;
        n = n>>1;
    }
    return ans;
}
int main()
{
    int base, exp;
    cout<<"Enter base and exponent :"<<endl;
    cin>>base>>exp;
    cout<<fastPower(base,exp);
    return 0;
}
