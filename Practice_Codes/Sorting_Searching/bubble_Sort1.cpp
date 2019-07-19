#include<iostream>
using namespace std;
int main()
{
    int a[100] = {0};
//    int n = sizeof(a)/sizeof(int);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //int minValue = 0,minIndex=0;
    for(int i=0;i<(n-1);i++)
    {
        for(int j=1;j<(n-i);j++)
        {
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

