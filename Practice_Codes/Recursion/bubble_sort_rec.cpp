#include<iostream>
using namespace std;
///Bubble Sort
void bubbleSort(int *a, int n)
{
    if(n==1)
    {
        return;
    }
    for(int j=0;j<(n-1);j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    ///last element is sorted!!!
    bubbleSort(a,n-1);

}

int main()
{
    int a[] = {3,5,1,2,7,10,6,3,4,2};
    int n = sizeof(a)/sizeof(int);
    bubbleSort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

