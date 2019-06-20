#include<iostream>
using namespace std;
int mul(int a, int b)
{
    if(a==0 | b==0)
    {
        return 0;
    }
    if(a==1)
    {
        return b;
    }
    if(b==1)
    {
        return a;
    }
    int ans = mul(a,b-1);
    return a + ans;

}
int main()
{

    int a,b;
    cin>>a>>b;
    cout<<"Multiplication : "<<mul(a,b)<<" ";

    return 0;
}


