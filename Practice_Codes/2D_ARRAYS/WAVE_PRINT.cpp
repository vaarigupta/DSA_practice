#include<iostream>
using namespace std;

/*

ARRAYS-WAVE PRINT COLUMN WISE
Take as input a two-d array. Wave print it column-wise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
///11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END
*/
void printArray(int a[][10], int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void wavePrint(int a[][10], int r, int c)
{
    for(int col=0;col<c;col++)
    {
        if((col&1) ==0)
        {
            for(int row=0;row<r;row++)
            {
                cout<<a[row][col]<<", ";
            }

        }
        else
        {
            for(int row=r-1;row>=0;row--)
            {
                cout<<a[row][col]<<", ";
            }

        }
    }
    cout<<"END";
}
int main()
{
    int a[10][10]={0};
    int r,c;

    cin>>r>>c;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    wavePrint(a,r,c);

    return 0;
}


