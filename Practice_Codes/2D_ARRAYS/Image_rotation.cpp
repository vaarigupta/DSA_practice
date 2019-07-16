#include<iostream>
using namespace std;
void imageRotation(int a[][100], int n)
{

    ///taking a transpose of the matrix
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }


    /// taking the mirror image horizantally of matrix
    for(int i=0;i<(n/2);i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(a[i][j],a[n-i-1][j]);
        }
    }
    ///Rotated 90 degree anticlockwise
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,a[100][100]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    imageRotation(a,n);
    return 0;
}



















/*

ROTATE IMAGE (N X N ARRAY)
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Input Format:
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints:
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13

*/


