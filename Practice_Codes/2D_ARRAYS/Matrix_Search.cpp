#include<iostream>
using namespace std;
bool matrixSearch(int a[][30], int n, int m,int key)
{
    ///staircase search
    int i=0, j=m-1;
    while(i<n && j>=0)
    {
        if(a[i][j]==key)
        {
            return 1;
        }
        else if (a[i][j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if(i==n || j<0)
    {
        return 0;
    }

}
int main()
{
    int n,m,key;
    cin>>n>>m;
    int a[30][30]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>key;
    cout<<matrixSearch(a,n,m,key);
	return 0;
}

/*
MATRIX SEARCH
Given an n x m matrix, where every row and column is sorted in increasing order, and a number x .
Find if element x is present in the matrix or not.

Input Format:
First line consists of two space separated integers N and M,
denoting the number of element in a row and column respectively.
 Second line of each test case consists of N*M space separated integers
 denoting the elements in the matrix in row major order.
 Third line of each test case contains a single integer x, the element to be searched.

Constraints:
1 <= N,M <= 30 0 <= A[i] <= 100

Output Format
Print 1 if the element is present in the matrix, else 0.

Sample Input
3 3
3 30 38
44 52 54
57 60 69
62
Sample Output
0
*/

