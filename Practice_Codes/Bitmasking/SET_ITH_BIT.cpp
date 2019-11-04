#include<iostream>
using namespace std;
int set_ith_bit(int n, int i)
{
    int mask = 1<<i;
    return (n|mask); /// OR of mask and no.
}

int main()
{
      int n,i;
      cin>>n>>i;
      cout<<set_ith_bit(n,i);


    return 0;
}





