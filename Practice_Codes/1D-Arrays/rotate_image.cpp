#include<iostream>
using namespace std;

void rotateAnti(int a[][100] , int n)
{
	/// transpose the matrix
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			swap(a[i][j],a[j][i]);
		}
	}
	/// Swap the rows - mirror image
	for(int i=0;i<(n/2);i++)
	{
		for(int j=0;j<n;j++)
		{
			swap(a[i][j], a[n-i-1][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int n;
	cin>>n;
	int arr[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	rotateAnti(arr, n);


	return 0;
}


