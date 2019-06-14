#include<iostream>
using namespace std;
int setithBit(int n, int i)
{
    return (n|(1<<i));
}
int main()
{
    int n,i;
    cout<<"Enter the number and ith bit to set: "<<endl;
    cin>>n>>i;
    cout<<"Number obtained after set bit : "<<setithBit(n,i)<<endl;
    return 0;
}
