#include<iostream>
using namespace std;
bool primeSieve(int *p , int key)
{
    p[0]=p[1] = 0;
    for(int i=2;i<=1000000;i++)
    {
        if((i&1) == 0)
        {
           p[i] = 0;
        }
        else
        {
            p[i] = 1;
        }
    }
    for(int i=3;i<=1000000;i+=2)
    {
        if(p[i])
        {
            for(int j=i*i;j<=1000000;j+=2)
            {
                p[j] = 0;
            }
        }
    }
    if(p[key])
    {
        return true;
    }
    else
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
