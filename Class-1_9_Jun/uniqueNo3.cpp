#include<iostream>
using namespace std;
int binToDec(int *a,int n)
{
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += ((a[i]%3)*(1<<i));
    }
    return ans;
}
int uniqueNo3(int *a, int n)
{
    int no[64] = {0};
    for(int i=0;i<n;i++)
    {
        int x = a[i];
        int j=0;
        while(x>0)
        {
            no[j] += (x&1);
            x >>= 1;
            j++;
        }
    }

    int ans =  binToDec(no,64);
    return ans;




}
int main()
{

    int a[] = { 1,2,2,3,3,3,1,1,2,4};
    int n = sizeof(a)/sizeof(int);
    cout<<"Unique No : "<<uniqueNo3(a,n);
    return 0;
}
