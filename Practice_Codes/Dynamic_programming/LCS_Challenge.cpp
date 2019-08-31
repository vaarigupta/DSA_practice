#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int lcs(string a, string b, int n, int m)
{
    if(n<0 || m<0)
    {
        return 0;
    }
    if(a[n]==b[m])
    {
        return 1 + lcs(a,b,n-1,m-1);
    }
    int op1 = lcs(a,b,n,m-1);
    int op2 = lcs(a,b,n-1,m);
    return max(op1,op2);

}
void lcsBU(string st1, string st2)
{
    int l1 = st1.length();
    int l2 = st2.length();
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
           if(i==0 || j==0)
           {
               dp[i][j] =0;
           }
           else if(st1[i-1]==st2[j-1])
           {
               dp[i][j] = 1 + dp[i-1][j-1];
           }
           else
           {
               dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
           }
        }
    }
    int i = l1,j=l2;
    int index = dp[i][j];
    char seq[index+1];
    seq[index] = '\0';
     while(i>=0 && j>=0)
    {

        if(st1[i-1]==st2[j-1])
        {
            seq[index-1] = st1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }

    }

    cout<<seq;
}
int main()
{
	string a, b;
	cin>>a>>b;
	int n = a.length()-1;
	int m = b.length() -1;
	lcsBU(a,b);
	return 0;
}


/*

bcde
abcd
0 0 0 0 0
0 0 1 1 1
0 0 1 2 2
0 0 1 2 3
0 0 1 2 3
3
*/
