#include<iostream>
using namespace std;
bool ratInMaze(char maze[][10],int i, int j, int m , int n)
{
    if(i==m && j==n)
    {
        return maze[i][j]=='0'?true: false;
    }

    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }

    bool rightseRastaHai = ratInMaze(maze, i, j+1, m,n);
    if(rightseRastaHai)
    {
        return true;
    }
    ///down se rasta
    return ratInMaze(maze, i+1,j,m,n);
}

//void ratInMazePrint(char maze[][10],int i, int j, int m , int n)
//{
//    if(i==m && j==n)
//    {
//        return maze[i][j]=='0'?true: false;
//    }
//
//    if(i>m || j>n)
//    {
//        return false;
//    }
//    if(maze[i][j]=='X')
//    {
//        return false;
//    }
//    maze[i][j] = '1';
//    bool rightseRastaHai = ratInMaze(maze, i, j+1, m,n);
//    bool downseRastaHai = ratInMaze(maze, i+1,j,m,n);
//}


int ratInMazeCount(char maze[][10],int i, int j, int m , int n)
{
    if(i==m && j==n)
    {
        return maze[i][j]=='0'?1:0;
    }

    if(i>m || j>n)
    {
        return 0;
    }
    if(maze[i][j]=='X')
    {
        return 0;
    }

    return ratInMazeCount(maze, i, j+1, m,n) + ratInMazeCount(maze, i+1,j,m,n);
}
int main()
{
    char maze[][10]=
    {

        "0000X",
        "00X0X0",
        "X00XX",
        "00000",
        "0XX00",
    };
    if(ratInMaze(maze,0,0,4,4)){
        cout<<"Rasta hai "<<endl;
    }
    else
    {
        cout<<"Rasta ni hai "<<endl;
    }
    cout<<ratInMazeCount(maze,0,0,4,4)<<endl;
    return 0;
}
