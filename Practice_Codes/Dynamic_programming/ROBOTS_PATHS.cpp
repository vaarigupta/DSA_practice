#include<iostream>
#include<cstring>
#define  mod 1000000007;
using namespace std;


int dp[1005][1005];
int robotPaths(int row, int col)
{
    /// if starting cell is blocked
    if(dp[0][0]== -1)
    {
        return 0;
    }
    for(int i=0;i<col;i++)
    {
        if(dp[0][i]== -1)
        {
            break;
        }
        dp[0][i] = 1;
    }
    for(int i=0;i<row;i++)
    {
        if(dp[i][0]== -1)
        {
            break;
        }
        dp[i][0] = 1;
    }

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(dp[i][j]== -1)
            {
                continue;
            }
            dp[i][j] = 0;
            if(dp[i-1][j]!= -1)
            {
               dp[i][j] = dp[i-1][j]%mod;
            }
            if(dp[i][j-1]!= -1)
            {
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }

        }
    }
//    for(int i=0;i<row;i++)
//    {
//        for(int j=0;j<col;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    if(dp[row-1][col-1]== -1)
    {
        return 0;
    }
        return dp[row-1][col-1];
}
int main()
{
    int m,n,p;
    memset(dp,0,sizeof(dp));
    cin>>m>>n>>p;
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
    }
    cout<<robotPaths(m,n);
    return 0;

}



/*

4 3 2
3 3
3 1
1 1 1
1 2 3
-1 2 -1
0 2 2
2

*/


