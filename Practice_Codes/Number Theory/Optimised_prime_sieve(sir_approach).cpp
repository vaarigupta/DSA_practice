#include<iostream>
using namespace std;
void primeSieve(int *p, int n)
{
    p[2] = 1;
    for(int i=3;i<=n;i+=2)
    {
        p[i] = 1;
    }

    for(int i=3;i<=n;i+=2)
    {
        if(p[i])
        {
            for(int j=i*i;j<=n;j+= (2*i))
            {
                p[j] = 0;
            }
        }
    }

}
int main()
{

   int n,i=0;
   cin>>n;
   int *p = new int[n]{0};
    primeSieve(p,n);
    cout<<2<<" ";
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)
        {
            cout<<i<<" ";
        }
    }

    return 0;
}

