#include<iostream>
using namespace std;
///Multiplication of two positive numbers
int mul(int x, int y)
{
    if(x== 0 || y== 0)
    {
        return 0;
    }
    if(x==1)
    {
        return y;
    }
    if(y==1)
    {
        return x;
    }
    int ans =0;
    ans += x + mul(x,y-1);
    return ans;
}
int main()
{
 int x,y;
 cin>>x>>y;
 cout<<mul(x,y);
    return 0;
}
