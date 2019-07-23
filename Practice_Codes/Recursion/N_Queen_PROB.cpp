#include<iostream>
using namespace std;
static int countQ = 0;

bool isSafe(int board[][12],int i,int j,int n)
{
    ///for same column
    for(int row=0;row<i;row++)
    {
        if(board[row][j])
        {
            return false;
        }
    }
    ///for left diagonal
    int x = i, y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y])
        {
            return false;
        }
        x--;
        y--;
    }
    ///for right diagonal
    x = i, y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y])
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool N_Queen(int board[][12], int i, int n)
{
    ///base case
    if(i==n)
    {
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(board[i][j])
//                {
//                    cout<<" Q ";
//                }
//                else
//                {
//                    cout<<" _ ";
//                }
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;
        countQ++;
        return false;
    }

    for(int col=0;col<n;col++)
    {
        if(isSafe(board,i,col,n))
        {
            board[i][col] = 1;

            bool nextGrid = N_Queen(board,i+1,n);
            if(nextGrid)
            {
                return true;
            }
            ///Backtracking bcz below(remaining grid ) returns false
            ///so we need to change the position of current queene and move on to the next
            board[i][col] = 0;
        }
    }
    return false;
}
int count_N_Queen()
{
    return countQ;
}
int main()
{
    int n;
    cin>>n;
    int board[12][12]={0};
    N_Queen(board,0,n);
    //cout<<endl;
    cout<<count_N_Queen()<<endl;

    return 0;
}

