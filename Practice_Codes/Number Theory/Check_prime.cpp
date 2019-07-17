#include<iostream>
using namespace std;
bool checkPrime(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    if(n&1 == 0)
    {
        return false;
    }
    for(int i=3;(i*i)<=n;i+=2)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(checkPrime(n))
    {
        cout<<n<<" is prime!!!"<<endl;
    }
    else
    {
       cout<<n<<" is not prime!!!"<<endl;
    }
    return 0;
}
