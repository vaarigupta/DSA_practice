#include<iostream>
using namespace std;
int partitionElement(int *a , int s , int e)
{
    int i= s-1;
    int pivot = a[e];
    for(int j=s;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    int p = i+1;
    swap(a[p],a[e]);
    return p;
}
void quicksort(int *a , int s, int e)
{
    ///Base case
    if(s>=e)
    {
        return;
    }
    int p = partitionElement(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}
int main()
{
    int a[100] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
