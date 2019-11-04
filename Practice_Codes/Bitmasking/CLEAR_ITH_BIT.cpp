#include<iostream>
using namespace std;
int clear_ith_bit(int n, int i)
{
    int mask = ~(1<<i);
    return (n&mask); /// AND of mask and no.
}

int main()
{
      int n,i;
      cin>>n>>i;
      cout<<clear_ith_bit(n,i);


    return 0;
}





