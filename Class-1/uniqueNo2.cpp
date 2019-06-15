#include<iostream>
using namespace std;
int main()
{
    int a[] = {1,1,2,2,3,3,4,5}, j=0;
    int n = sizeof(a)/sizeof(int), res=0;
    for(int i=0;i<n;i++)
    {
        res ^= a[i];
    }
    int temp;
    temp = res;
    while(temp> 0)
    {
        if(res&1)
        {
            break;
        }
        j++;
        res >>= 1;
    }
    return 0;
}
