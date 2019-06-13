#include<iostream>
using namespace std;
bool even_odd(int n)
{
    if(n&1 == 0)
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
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    if(even_odd(n))
    {
        cout<<n<<" is even"<<endl;
    }
    else
    {
        cout<<n<<" is odd"<<endl;
    }
    return 0;
}
