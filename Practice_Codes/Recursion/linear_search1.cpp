#include<iostream>
using namespace std;
int linearSearch(int *a,int i, int n, int key)
{
    if(n==0)
    {
        return -1;
    }
    if(a[i]==key)
    {
        return i;
    }
    return linearSearch(a,i+1,n,key);
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
	cout<<linearSearch(a,0,n,key);
	return 0;
}

