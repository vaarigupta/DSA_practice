#include<iostream>
#define ll signed long long
using namespace std;
ll chewbacca(ll x)
{
    int a[100]={0},i=0,p=1;
    ll ans=0;
    while(x!=0)
    {
        a[i] = x%10;
        x = x/10;
        i++;
    }
    int n = i-1;
    for(int j=0;j<=n;j++)
    {
        if(a[j]>4 && j<n)
        {
            a[j] = 9 - a[j];

        }
        if(a[n]==9)
        {
            a[n] = 9;
        }
        ans += a[j]*p;
        p *= 10;

    }
    return ans;
}
int main()
{
    ll x,ans=0;
    cin>>x;
    ans = chewbacca(x);
    cout<<ans;

    return 0;
}

















/*

CHEWBACCA AND NUMBER
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them.
Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits.
The decimal representation of the final number shouldn't start with a zero.

Input Format:
The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

Constraints:
x <= 100000000000000000

Output Format
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Sample Input
4545
Sample Output
4444

*/
