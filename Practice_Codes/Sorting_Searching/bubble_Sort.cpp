#include<iostream>
using namespace std;
///Bubble Sort
int main()
{
    int a[] = {3,5,1,2,7,10,6,3,4,2};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i);j++)
        {
            if(a[j]>a[j+1] &&((j+1)<n))
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
