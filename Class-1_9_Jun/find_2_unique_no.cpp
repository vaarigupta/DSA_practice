#include<iostream>
using namespace std;
int main()
{
    int unique1 =0, unique2=0;
    int a[]= {1,3,4,5,5,4,3,6};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        unique1 ^= a[i];
    }
    int temp = unique1;
    int p =0;
    while((temp&1)==0)
    {
        p++;
        temp = temp>>1;
    }
    int setA = 0;
    int mask = (1<<p);

    return 0;
}
