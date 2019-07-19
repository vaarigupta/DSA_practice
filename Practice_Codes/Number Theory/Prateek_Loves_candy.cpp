#include<iostream>
using namespace std;
int a[1000010]={0};
void primeSieve(int *p)
{
    p[2] = 1;
    for(int i=3;i<=1000000;i+=2)
    {
        p[i] = 1;
    }

    for(int i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(int j=i*i;j<=1000000;j+= (2*i))
            {
                p[j] = 0;
            }
        }
    }
    a[1] = 2;
    int k=2;
    for(int i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            a[k] = i;
            k++;
        }
    }

}
int main()
{
    int *p = new int[1000010]{0};
    int t,n;
    cin>>t;
    primeSieve(p);
    for(int i=0;i<t;i++)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }

    return 0;
}



/*

PRATEEK LOVES CANDY
Prateek recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Prateek wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Prateek bhaiya it is now your job to help him out :)

Input Format:
First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.

Constraints:
T <= 10000

It is guaranteed that the answer does not exceed 10^6.

Output Format
Print the minimum cost that needs to be paid.

Sample Input
2
5
1
Sample Output
11
2
*/






