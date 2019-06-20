#include<iostream>
using namespace std;
int binary_search(int *a, int s, int e, int key)
{
    if(s>e)
    {
        return -1;
    }
    if(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        if(a[mid]<key)
        {
            return binary_search(a,mid+1,e,key);
        }
        if(a[mid]>key)
        {
            return binary_search(a,s,mid-1,key);
        }
    }

}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(a)/sizeof(int),key;
    cout<<"Enter the value :"<<endl;
    cin>>key;
    int ans = binary_search(a,0,n,key);
    if(ans!= (-1))
    {
        cout<<key<<"is found at "<<ans+1<<endl;
    }
    else
    {
        cout<<key<<" not found "<<endl;
    }

    return 0;
}
