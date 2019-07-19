#include<iostream>
#define ll long long
using namespace std;
ll p[100000000];
ll a[100000000];
ll no = 100000000;
void primeSieve()
{
    p[0] = p[1] = 0;
    for(ll i=2;i<=no;i++)
    {
        if(p[i])
        {
            for(ll j=(2*i);j<=no;j+=i)
            {
                p[j] =0;
            }
        }
    }
}

int main()
{
    int n,k=1;
    fill(p,p+no,1);
    primeSieve();
    a[0]=2;
    for(ll i=3;i<=no;i+=2)
    {
        if(p[i])
        {
            a[k++]= i;
        }
    }
    cin>>n;
    cout<<a[n-1];
    return 0;
}


/*

DEEPAK AND PRIMES
Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

Input Format:
Single line containing integral value n.

Constraints:
1<=n<=5000000

Output Format
Integral value denoting nth prime number.

Sample Input
1
Sample Output
2
*/
