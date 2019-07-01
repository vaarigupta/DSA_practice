#include<iostream>
using namespace std;
int lower(int *a,int n, int key)
{
    int s=0, e= (n-1);
    int ans =-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            e = mid-1;
        }

        if(a[mid]<key)
        {
            s = mid+1;
        }
        if(a[mid]>key)
        {
            e = mid-1;
        }

    }

    return ans;
}

int upper(int *a,int n, int key)
{
    int s=0, e= (n-1);
    int ans =-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            s = mid+1;
        }

        if(a[mid]<key)
        {
            s = mid+1;
        }
        if(a[mid]>key)
        {
            e = mid-1;
        }

    }

    return ans;
}
int main() {
    int n,a[10],t, test[5];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>test[i];
    }
    for(int i=0;i<t;i++)
    {
        cout<<lower(a,n,test[i])<<" "<<upper(a,n,test[i])<<endl;
    }
	return 0;
}


