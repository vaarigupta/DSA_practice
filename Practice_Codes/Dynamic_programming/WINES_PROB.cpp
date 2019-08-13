#include<iostream>
using namespace std;
int max_profit(int *wines,int i, int j, int day)
{
   if(i>j)
   {
       return 0;
   }
    int op1 = wines[i]*day + max_profit(wines,i+1,j,day+1);
    int op2 = wines[j]*day + max_profit(wines,i,j-1,day+1);
    int ans = max(op1,op2);
    return ans;

}
int max_profitTD(int *wines,int i, int j, int day,int dp[100][100])
{
   if(i>j)
   {
       return 0;
   }
   if(dp[i][j]!=0)
   {
      return dp[i][j];
   }
    int op1 = wines[i]*day + max_profitTD(wines,i+1,j,day+1,dp);
    int op2 = wines[j]*day + max_profitTD(wines,i,j-1,day+1,dp);
    int ans = max(op1,op2);
    dp[i][j] = ans;
    return dp[i][j];

}
void max_profitBU()
{
//   int dp[100][100];
//   int k=1;
//    for(int i=0;i<3;i++)
//    {
//        for(int j=0;j<3;j++)
//        {
//            dp[i][j] = k;
//            k++;
//        }
//    }
//   for(int i=0,j=0;i<3&&j<3;i++,j++)
//   {
//
//   }
}
int main()
{
    int dp[100][100]={0};
    int wines[] = {2,4,6,2,5};
    int n = sizeof(wines)/sizeof(int);
    cout<<"Recursive sol :"<<endl<<max_profit(wines,0,n-1,1)<<endl;
    cout<<"Top down sol :"<<endl<<max_profitTD(wines,0,n-1,1,dp)<<endl;
    //max_profitBU();


    return 0;
}

