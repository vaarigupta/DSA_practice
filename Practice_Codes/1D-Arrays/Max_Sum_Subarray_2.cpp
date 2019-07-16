#include<iostream>
using namespace std;

///generating subarrays - in o(n2) time - Using cumulative Sum (precomputation)
void maxSum(int a[], int n, int cs[])
{
    int currSum, maxSum1 = -100, x=0, y=0;
    //currSum = cs[0];
    for(int i=0;i<n;i++)
    {
       for(int j=i;j<n;j++)
       {
           if(i>=1)
           {
               currSum = cs[j] - cs[i-1];
           }
           else
           {
               currSum = cs[j];
           }
           if(currSum> maxSum1)
           {
               maxSum1= currSum;
               x = i;
               y = j;
           }
       }
    }
    cout<<"Max Sum :"<<maxSum1<<endl;
    cout<<"Subarray :"<<endl;
    for(int i=x;i<=y;i++)
    {
        cout<<a[i]<<" ,";
    }
}
int main()
{
    int a[100]={0}, cs[100]={0},n;
    cin>>n;
    cin>>a[0];
    cs[0] = a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        cs[i] = cs[i-1]+ a[i];

    }
    maxSum(a,n,cs);
    return 0;
}

