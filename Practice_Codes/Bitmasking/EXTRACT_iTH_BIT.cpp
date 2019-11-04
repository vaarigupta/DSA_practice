#include<iostream>
using namespace std;
int ith_bit(int n, int i)
{
    int mask = 1<<i; /// create a mask of 1 if AND of this with number gives a number
    /// means bit is 1 and if it returns 0 then bit is also 0
    if(n&mask)
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
      int n,i;
      cin>>n>>i;
      cout<<ith_bit(n,i);


    return 0;
}




