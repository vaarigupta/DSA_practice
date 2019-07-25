#include<iostream>
using namespace std;
int binarySearch(int *a,int s, int e, int key)
{

    if(s>e)
    {
        return -1;
    }
    if(s<=e)
    {
        int mid = (s+e)/2;
       if(a[mid]==key)
    {
        return mid;
    }
    else if(a[mid]<key)
    {
        return binarySearch(a,mid+1,e,key);
    }
    else
    {
        return binarySearch(a,s,mid-1,key);
    }
    }

}

int main(){

	int n,key;
	cin>>n;
	int a[1000];

	for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
	cin>>key;
	cout<<binarySearch(a,0,n-1,key);
	return 0;
}


