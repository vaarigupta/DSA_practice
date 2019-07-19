#include<iostream>
using namespace std;
int main()
{
    int a[100] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int minValue = 0,minIndex=0;
    for(int i=0;i<(n-1);i++)
    {
        minValue = a[i];
        minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(minValue>a[j])
            {
                minValue = a[j];
                minIndex = j;
            }

        }
        swap(a[i],a[minIndex]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
