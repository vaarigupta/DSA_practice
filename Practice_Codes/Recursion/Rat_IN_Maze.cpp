#include<iostream>
using namespace std;
char maze[1005][1005];
int sol[1005][1005]={0};
bool ratInMaze(char maze[][1005],int sol[][1005], int n , int m , int i , int j)
{
    if(i==(n-1) && j==(m-1))
    {
        sol[i][j] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(i>=n || j>=m)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    sol[i][j] = 1;
    bool rightWays = ratInMaze(maze,sol,n,m,i,j+1);
    bool downWays = ratInMaze(maze,sol,n,m,i+1,j);

    ///backtracking
        sol[i][j] = 0;
    if(rightWays || downWays)
    {
        return true;
    }
    return false;

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }
    ratInMaze(maze,sol,n,m,0,0);


    return 0;
}


