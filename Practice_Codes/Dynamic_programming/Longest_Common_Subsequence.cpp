#include<iostream>
#include<cstring>
using namespace std;

int lcs(string l1, string l2, int n, int m)
{
    ///base case
    if(n==0 || m==0)
    {
        return 0;
    }
    ///rec case
    if(l1[n-1]==l2[m-1])
    {
        return 1 + lcs(l1,l2,n-1,m-1);
    }
    int op1 =lcs(l1,l2,n,m-1);
    int op2 = lcs(l1,l2,n-1,m);
    return max(op1,op2);
}

int lcsBU(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[100][100];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
                continue;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int x=l1;
    int y=l2;
    while(x>0 || y>0)
    {

        if(dp[x][y] == (dp[x-1][y-1]+1))
        {
            cout<<s1[x-1];
            //cout<<"s2 : "<<s2[y-1]<<endl;
            x--;
            y--;
        }
        else if(dp[x][y] == dp[x-1][y])
        {
            //cout<<s1[x-1];
            x--;
        }
        else
        {
            //cout<<s1[y-1];
            y--;
        }
    }
    cout<<endl;
    return dp[l1][l2];

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    char a[100];
    int l1 = s1.length();
    int l2 = s2.length();
    cout<<lcs(s1,s2,l1,l2)<<endl;
   //cout<<lcsBU(s1,s2)<<endl;

    return 0;

}


/*

mapen apple
3
0 0 0 0 0 0
0 0 0 0 0 0
0 1 1 1 1 1
0 1 2 2 2 2
0 1 2 2 2 3
0 1 2 2 2 3
3

*/
