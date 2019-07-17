#include<iostream>
using namespace std;
///Create Prime sieve  - array of 1 and 0 which denotes no is prime or not respectively
bool primeSieve(int *p, int key)
{
    for(int i=2;i<=1000000;i++)
    {
        p[i] = 1;
    }
    p[0]=p[1] = 0;
    for(int i=2;i<=1000000;i++)
    {
        if(p[i])
        {
            for(int j=2*i;j<=1000000;j+=i)
            {
                p[j] = 0;
            }
        }

    }
    if(p[key]==1)
    {
        return true;
    }
    if(p[key]==0)
    {
        return false;
    }
}
int main()
{
    int *p = new int[1000000];
    int key;
    cin>>key;
    if(primeSieve(p,key))
    {
        cout<<key<<" is prime!!!"<<endl;
    }
    else
    {
       cout<<key<<" is not prime!!!"<<endl;
    }
    return 0;
}

