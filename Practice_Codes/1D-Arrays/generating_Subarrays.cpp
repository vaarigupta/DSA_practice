#include<iostream>
using namespace std;

///generating subarrays - in o(n3) time
int main()
{
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<a[k]<<",";
            }
            cout<<endl;

        }
    }
    return 0;
}
