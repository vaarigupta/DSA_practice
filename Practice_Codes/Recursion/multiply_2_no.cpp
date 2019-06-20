#include<iostream>
using namespace std;
int mul(int a, int b)
{
    int ans;
    if(a==0 | b==0)
    {
        return 0;
    }
    if(a<0)
    {
        ans = mul(a,b-1);
        return a + ans;
    }
    if(b<0)
    {
        ans = mul(a-1,b);
        return b + ans;
    }
    if(a>0 && b>0)
    {
        ans = mul(a,b-1);
        return a + ans;
    }

    ///How to do it for negative numbers
//    if(a<0 && b<0)
//    {
//       a = (-1)*a;
//       b = (-1)*b;
//       ans = mul(a,b-1);
//       return a + ans;
//    }

}
int main()
{

    int a,b;
    cin>>a>>b;
    cout<<"Multiplication : "<<mul(a,b)<<" ";

    return 0;
}
