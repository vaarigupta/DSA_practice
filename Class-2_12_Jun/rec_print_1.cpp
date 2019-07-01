#include<iostream>
using namespace std;
///Top down approach
void dec(int n)
{
    if(n==0)
    {
        return;
    }

    ///rec case
    cout<<n<<" ";
    return dec(n-1);
}
///Bottom up approach
void inc(int n)
{
    if(n==0)
    {
        return;
    }
    inc(n-1);
    cout<<n<<" ";

}
int main()
{
   int n;
   cin>>n;
   dec(n);
   cout<<endl;
   inc(n);
    return 0;
}

