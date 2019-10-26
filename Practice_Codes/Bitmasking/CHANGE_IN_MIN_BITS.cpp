#include<iostream>
using namespace std;
int min_bits_changed(int a, int b)
{
    int XOR = (a^b);
    int count = 0;
    while(XOR>0)
    {
       count += (XOR&1);
       XOR >>= 1;
    }
    return count;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<min_bits_changed(a,b);


    return 0;
}

