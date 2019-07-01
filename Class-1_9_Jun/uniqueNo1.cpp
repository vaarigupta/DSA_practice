#include<iostream>
using namespace std;
int main()
{
    int a[] = {2,2,3,3,4,4,5,5,6,6,7,7,8}, num=0;
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        num ^= a[i];
    }
    cout<<"Num : "<<num;
    return 0;
}

