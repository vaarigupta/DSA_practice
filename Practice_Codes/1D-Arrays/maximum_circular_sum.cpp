#include<iostream>
using namespace std;
/// use kadane and find first candidate
/// Invert the sign of every element of the array
/// apply kadane of new inverted array - gives min sum subarray
/// subtract the negative value of new sum from cumulative sum of original array gives new candidate 2
/// return largest of both candidate

int kadane(int *a, int n)
{
    int cs = 0, ms = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cs += a[i];
        if(cs < 0)
        {
            cs = 0;
        }
        if(cs >ms)
        {
            ms = cs;
        }
    }
    return ms;
}
int inversion(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        a[i] *= (-1);
    }
    int ms = kadane(a,n);
    return (-1)*ms;
}
int max_sum_circular(int *a, int n)
{

    int cand1 = kadane(a,n);
    int cumSum = 0;
    for(int i=0;i<n;i++)
    {
        cumSum += a[i];
    }
    int invert = inversion(a,n);
    int cand2 = cumSum - invert;
    return max(cand1,cand2);



}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[1005];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<max_sum_circular(a,n)<<endl;
    }
    return 0;
}
