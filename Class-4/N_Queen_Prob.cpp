#include<iostream>
using namespace std;
bool canPlace(int board[][10], int i, int j , int n)
{
    ///columns
    for(int x=0;x<i;x++)
    {
        if(board[x][j]==1)
        {
            return false;
        }
    }
    ///diag
    int x=i, y=j;
    ///left diag
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    ///right diag
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return true;
        }
        x--;
        y++;
    }

}
int nQueen(int board[][10],int i,int n)
{
    if(i==n)
    {
        return 1;
    }
    ///rec case
    int cnt =0;
    for(int j=0;j<n;j++)
    {
        if(canPlace(board,i,j,n))
        {
            board[i][j] = 1;
            cnt += nQueen(board,i+1,n);
            board[i][j] = 0;
        }
    }
    return cnt;
}

int main()
{
    int board[10][10] = {0};
    cout<<nQueen(board,0,4);
    return 0;
}

//if(i>m || j>n)
//    {
//        return;
//    }
//    if(board[i+1][j] || board[i][j+1] || board[i+1][j+1])
//    {
//        return;
//    }
//    nQueen(board,i+1,j,m,n);
//    nQueen(board,i, j+1,m,n);
//    nQueen(board,i+1,j+1,m,n);
