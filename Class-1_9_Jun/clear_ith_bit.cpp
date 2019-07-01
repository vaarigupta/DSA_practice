#include<iostream>
using namespace std;
int clear_ith_Bit(int n, int i)
{
    int mask = (~(1<<i));
    return (n&mask);
}
int main()
{
    int n,i;
    cout<<"Enter the number and the ith bit : " <<endl;
    cin>>n>>i;
    cout<<clear_ith_Bit(n,i);

    return 0;
}

