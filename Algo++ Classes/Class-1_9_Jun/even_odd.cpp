#include<iostream>
using namespace std;
bool check_if_even(int n)
{
    if(n&1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    if(check_if_even(n))
    {
        cout<<n<<" is even"<<endl;
    }
    else
    {
        cout<<n<<" is odd"<<endl;
    }
    return 0;
}
