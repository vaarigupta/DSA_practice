#include<iostream>
using namespace std;
int fib(int n)
{
    switch(n)
    {
        case 0:
            return 0;
            break;
        case 1:
            return 1;
            break;
        default:
            return fib(n-1) + fib(n-2);
            break;
    }

}
int main()
{
    int n;
    cin>>n;
    cout<<"factorial :"<<fib(n)<<" "<<endl;
    return 0;
}

