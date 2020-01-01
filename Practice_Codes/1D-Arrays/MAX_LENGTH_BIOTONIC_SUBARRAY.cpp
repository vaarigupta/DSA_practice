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
      if(a[i]>= a[i+1])
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

