#include<iostream>
using namespace std;
///Fibonacci Series using Recursion
int fib(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }

    return (fib(n-1)+fib(n-2));
}
int main()
{
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";
    }

    return 0;
}






