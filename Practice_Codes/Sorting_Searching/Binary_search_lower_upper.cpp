#include<iostream>
using namespace std;
int lower(int *a, int s, int e, int key)
{
    int mid, minIndex=-1;
    while(s<=e)
    {
        mid =(s+e)/2;
        if(a[mid]==key)
        {
            minIndex = mid;
            e = mid-1;
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
        return minIndex;
    }
}
int upper(int *a, int s, int e, int key)
{
    int mid,maxIndex=-1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(a[mid]==key)
        {
            maxIndex = mid;
            s = mid+1;

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
        return maxIndex;
    }
}
int main()
{
    int a[100] = {0};
    int n,t,key;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>t;
    while(t--)
    {
        cin>>key;
        int l = lower(a,0,n-1,key);
        int u = upper(a,0,n-1,key);
        cout<<l<<" "<<u<<endl;
    }
    return 0;
}

