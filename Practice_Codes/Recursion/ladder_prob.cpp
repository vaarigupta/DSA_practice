#include<iostream>
using namespace std;

///top down approach - O(pow(k,n) - exponential
int ladder_prob(int n, int k)
{
    int ans = 0;
    ///base case
    if(n==0 || n==1)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }

    ///rec case
    for(int i=1;i<=k;i++)
    {
        ans+= ladder_prob(n-i,k);
    }
    return ans;


}

///bottom up approach /// O(nk)
int ladder_prob_iterative(int n , int k)
{
    int a[100]={0};
    a[0] =1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            {
                a[i] += a[i-j];
            }

        }
        //cout<<a[i]<<" ";
    }
    return a[n];
}

///Optimized approach  - O(n+k)

int ladder_prob_optimized(int n, int k)
{
    int a[100] = {0};
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if((i-1)>=0)
        {
          a[i] = (2*a[i-1]);
          if((i-(k+1))>=0)
          {
              a[i] -= a[i-(k+1)];
          }
        }

    }

    return a[n];
}
int main()
{
    int steps, jumps;
    cout<<"Enter the steps and jumps :"<<endl;
    cin>>steps>>jumps;
    int ans=0;
    ans = ladder_prob(steps, jumps);
    cout<<"Top down approach :"<<ans<<endl;
    ans = ladder_prob_iterative(steps, jumps);
    cout<<"Bottom up approach :"<<ans<<endl;
    ans = ladder_prob_optimized(steps, jumps);
    cout<<"Optimized approach :"<<ans<<endl;

///ladder_prob_iterative(steps,jumps);
    return 0;
}
