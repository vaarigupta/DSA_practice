#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }

    return n*fact(n-1);
}
int main()
{
    int n ;
    cout<<"enter the no : "<<endl;
    cin>>n;
    cout<<"Factorial of number : "<<fact(n)<<endl;
    return 0;
}


