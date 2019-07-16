#include<iostream>
using namespace std;

///generating subarrays - in o(n3) time
void maxSum(int a[], int n)
{
    int currSum = 0, maxSum1 = -100, x=0, y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currSum = 0;
            for(int k=i;k<=j;k++)
            {
                //cout<<a[k]<<" ";

                currSum += a[k];
            }
            if(currSum> maxSum1)
            {
                x=i;
                y=j;
                maxSum1 =currSum;
            }

        }
    }
    cout<<"Max Sum :"<<maxSum1<<endl;
    for(int i=x;i<=y;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[] = {-4,1,3,-2,6,2,-1,4,-7};
    int n = sizeof(a)/sizeof(int);
    maxSum(a,n);
    return 0;
}

