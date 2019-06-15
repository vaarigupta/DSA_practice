#include<iostream>
using namespace std;
///Merge Sort

int* mergeArr(int *arr, int s , int e)
{

    int mid= (s+e)/2, j= mid+1,i=s, k=s;
    int temp[1000];
    while(i<=mid && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=e)
    {
        temp[k++] = arr[j++];
    }
    return temp;
}
int mergeSort(int *arr, int s, int e)
{
    if(s==e)
    {
        return 0;
    }
    int n = (s+e)/2;
    mergeSort(arr,s,n);
    mergeSort(arr,n+1,e);

    return mergeArr(arr,s,e);


}
int main()
{

int arr[] = {1,3,2,4,6,5};
int n = sizeof(arr)/sizeof(int);
arr = mergeSort(arr,0, n-1);
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}

    return 0;
}


