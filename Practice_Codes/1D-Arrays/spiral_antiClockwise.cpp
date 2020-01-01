#include<iostream>
using namespace std;
void sprialAntiClockwise(int arr[10][10] , int row, int col)
{
	int top = 0 , bottom = row -1 , left = 0, right = col-1;
	while(top<=bottom && left<=right)
	{
		//top to bottom
		for(int i=top;i<bottom;i++)
		{
			cout<<arr[i][left]<<", ";
		}
		// left to right
		for(int i=left; i<right;i++)
		{
			cout<<arr[bottom][i]<<", ";
		}
		// bottom to top
		for(int i=bottom;i>top;i--)
		{
			cout<<arr[i][right]<<", ";
		}
		// right to left
		for(int i=right;i>left;i--)
		{
			cout<<arr[top][i]<<", ";
		}
		top++;
		bottom--;
		left++;
		right--;
	}
	cout<<"END";
}
int main() {
	int arr[10][10] , row, col;
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>arr[i][j];
		}
	}
	sprialAntiClockwise(arr,row,col);
	return 0;
}
