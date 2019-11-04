#include<iostream>
using namespace std;
int xor_swap(int &a,int &b)
{
    a = a^b;
    b = a^b; /// b = a^b^b = a
    a = a^b; /// a = a^b^a = b - hence swapped

}
int main()
{
    int a,b;
    cin>>a>>b;
    xor_swap(a,b);
    cout<<"After swapping "<<a<<" "<<b;


    return 0;
}



