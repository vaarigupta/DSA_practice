#include<iostream>
using namespace std;
int binarySearch(int *a, int s, int e, int key)
{
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]<key)
        {
            s = mid +1;
        }
        else
        {
            e = mid-1;
        }
    }
    if(s>e)
    {
        return -1;
    }
}
int main()
{
    int a[100] = {0};
//    int n = sizeof(a)/sizeof(int);
    int n,key;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>key;
    cout<<key<<" is found at "<<binarySearch(a,0,n-1,key)<<endl;
    return 0;
}
