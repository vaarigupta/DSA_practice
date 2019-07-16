#include<iostream>
using namespace std;

///generating max sum of subarray in o(n) time - "KADANE ALGO"
void maxSum(int a[], int n)
{
    int currSum = 0, maxSum1 = 0;
    for(int i=0;i<n;i++)
    {
       currSum += a[i];
       if(currSum<0)
       {
           currSum = 0;
       }
       maxSum1 = max(maxSum1,currSum);
    }
    cout<<"Max Sum :"<<maxSum1<<endl;
//    for(int i=x;i<=y;i++)
//    {
//        cout<<a[i]<<" ";
//    }
}
int main()
{
    int a[100]={0},n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxSum(a,n);
    return 0;
}

