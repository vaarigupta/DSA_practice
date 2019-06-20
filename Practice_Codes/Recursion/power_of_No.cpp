#include<iostream>
using namespace std;
int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    return a*power(a,b-1);

}
int fastPower(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    int ans = fastPower(a,b>>1)*fastPower(a,b>>1);
    if((b&1)==0)
    {
        return ans;
    }
    if((b&1)==1)
    {
        return a*ans;
    }
}

///sir optimization and method of writing code
int fastPower1(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    int ans = fastPower(a,b>>1);
    ans *= ans;
    if((b&1))
    {
        return a*ans;
    }
    return ans;

}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"Power of number :"<<power(a,b)<<" "<<endl;
    cout<<"Fast Power of number :"<<fastPower1(a,b)<<" "<<endl;
    return 0;
}
