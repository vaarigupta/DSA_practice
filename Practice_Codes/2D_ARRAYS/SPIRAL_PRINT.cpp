#include<iostream>
using namespace std;

/*

ARRAYS-SPIRAL PRINT ANTICLOCKWISE
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END


Enter rows and cols :
4 4
Enter elements :
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1 5 9 13 14 15 16 12 8 4 3 2 6 10 11 7

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
void spiralPrint(int a[][10], int r , int c)
{
    int startrow = 0, endrow = r-1, startcol = 0, endcol = c-1;
    while(startrow<=endrow && startcol<=endcol)
    {
        ///start col fixed and  row changes  0 to endrow
        if(startcol<=endcol)
        {for(int i=startrow ; i<=endrow;i++)
           {
               cout<<a[i][startcol]<<", ";
           }

        }

            startcol++;
        ///end row fixed and col changes col+1 to endcol
            if(startrow<=endrow)
            {
                for(int i=startcol;i<=endcol;i++)
            {
                cout<<a[endrow][i]<<", ";
            }
            }

            endrow--;
        /// end col fixed and row changes from endrow-1 to startrow
            if(startcol<=endcol)
            {
                 for(int i=endrow;i>=startrow;i--)
                {
                    cout<<a[i][endcol]<<", ";
                }

            }

            endcol--;
        ///startrow fixed and col changes from endcol-1 to startcol
            if(startrow<=endrow)
            {
            for(int i=endcol;i>=startcol;i--)
            {
                cout<<a[startrow][i]<<", ";
            }
            }

            startrow++;
    }
    cout<<"END";
}
int main()
{
    int a[10][10]={0};
    int r,c,key;
    cout<<"Enter rows and cols :"<<endl;
    cin>>r>>c;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    printArray(a,r,c);
    spiralPrint(a,r,c);


    return 0;
}




