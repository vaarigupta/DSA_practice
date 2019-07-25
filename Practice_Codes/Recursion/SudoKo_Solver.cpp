#include<iostream>
#include<cmath>
using namespace std;
bool canPlace(int a[][100],int i,int j,int n, int num)
{
    for(int k=0;k<n;k++)
    {
        if(a[i][k]== num || a[k][j]==num)
        {
            return false;
        }
    }

    int sq = sqrt(n);
    int sx = (i/sq)*sq;
    int sy = (j/sq)*sq;

    for(int x= sx; x<sx+sq ;x++)
    {
        for(int y= sy; y<sy+sq ;y++)
        {
            if(a[x][y]==num)
            {
                return false;
            }
        }
    }

   return true;
}
bool sudokuSolver(int a[][100], int i, int j , int n)
{
    ///Base Case
    if(i==n)
    {

        ///print sudoku
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        return true;
    }
    if(j==n)
    {
        return sudokuSolver(a,i+1,0,n);
    }
    if(a[i][j]!=0)
    {
        return sudokuSolver(a,i,j+1,n);
    }
    ///Recursive Case
    for(int num=1;num<=n;num++)
    {
        if(canPlace(a,i,j,n,num))
        {
            a[i][j] = num;
            bool remainingGrid = sudokuSolver(a,i,j+1,n);
            if(remainingGrid)
            {
                return true;
            }
        }

    }
    ///backtracking
    a[i][j] = 0;
    return false;

}
int main()
{
    int n;
    int sudoku[100][100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    sudokuSolver(sudoku,0,0,n);
    return 0;
}

