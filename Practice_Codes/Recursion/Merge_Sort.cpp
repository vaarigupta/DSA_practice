#include<iostream>
using namespace std;
void merge(int *a, int *p , int *q, int s, int e)
{
    int mid=(s+e)/2;
    int i=s, j= mid+1, k=s;
    while(i<=mid && j<=e)
    {
        if(p[i]<=q[j])
        {
            a[k++] = p[i++];
        }
        else
        {
            a[k++] = q[j++];
        }
    }

    while(i<=mid)
    {
        a[k++] = p[i++];
    }
    while(j<=e)
    {
        a[k++] = q[j++];
    }
}
void mergeSort(int *a, int s, int e)
{
    ///Base case
    if(s>=e)
    {
        return;
    }

    ///Divide the array
    int mid = (s+e)/2;
    int left[100], right[100];
    for(int i=s;i<=mid;i++)
    {
        left[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++)
    {
        right[i] = a[i];
    }
    ///Call mergesort
    mergeSort(left,s,mid);
    mergeSort(right,mid+1,e);

    ///Merging the elements
    merge(a,left, right, s,e);
}
int main()
{
    int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

