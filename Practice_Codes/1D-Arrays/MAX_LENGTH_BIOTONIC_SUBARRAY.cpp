#include<iostream>
#define ll long long
#define range 1000006
using namespace std;
int max_length(ll *a, int n)
{
  ll inc[range] , dec[range];
  inc[0] = 1, dec[n-1] = 1;
  /// increasing sequence
  for(int i=1;i<n;i++)
  {
      if(a[i-1]<=a[i])
      {
          inc[i] = inc[i-1] + 1;
      }
      else
      {
          inc[i] = 1;
      }
  }
  for(int i=n-2;i>=0;i--)
  {
      if(a[i]<= a[i+1])
      {
          dec[i] = dec[i+1] +1;
      }
      else
      {
          dec[i] = 1;
      }
  }

  int max_len = 0;
  for(int i=0;i<n;i++)
  {
      int len = inc[i] + dec[i] - 1;
      max_len = max(len,max_len);
  }
  return max_len;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[range];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int len = max_length(a,n);
        cout<<len<<endl;
    }
    return 0;
}


/*

MAXIMUM LENGTH BIOTONIC SUBARRAY
You are provided n numbers of array. You need to find the maximum length of bitonic subarray.
A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]
i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

Input Format:
First line contains integer t which is number of test case. For each test case,
it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints:
1<=t<=100 1<=n<=1000000

Output Format
Print the maximum length.

Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output
5
4
*/
