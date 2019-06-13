#include<iostream>
using namespace std;
int getLastBit(int n)
{
    if(n&1==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    cout<<"The last Bit : "<<getLastBit(n)<<endl;

    return 0;
}
