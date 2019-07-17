#include<iostream>
#define ll long long int
using namespace std;
ll fact(int n, ll *dp)
{
    if(n==1 || n==0)
    {
        dp[0] = 1;
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    return dp[n] = n*fact(n-1,dp);
}
int main()
{
    int n;
    ll dp[100000] = {0};
    cin>>n;
    cout<<fact(n , dp);
    return 0;
}



/*

BROKEN CALCULATOR
Andrew was attempting a mathematics test where he needed to solve problems with factorials. One such problem had an answer which equaled 100! ,He wondered what would this number look like. He tried to calculate 100! On his scientific calculator but failed to get a correct answer. Can you write a code to help Andrew calculate factorials of such large numbers?

Input Format:
a single lined integer N

Constraints:
1 < = N < = 500

Output Format
Print the factorial of N

Sample Input
5
Sample Output
120

*/
