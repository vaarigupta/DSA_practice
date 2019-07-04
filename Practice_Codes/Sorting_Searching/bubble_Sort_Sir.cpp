#include<iostream>
using namespace std;
int main()
{
    int a[] = {3,5,1,2,7,10,6,3,4,2};
    int n = sizeof(a)/sizeof(int);

    for(int t=1;t<=(n-1);t++)
    {
        for(int j=0;j<=(n-1-t);j++)
        {
            if(a[j]>a[j+1])
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
