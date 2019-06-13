#include<iostream>
using namespace std;

///Efficient way to sort
void XOR_Swap(int n ,int m)
{
    n = n^m;
    m = n^m;
    n = n^m;
    cout<<"After swapping : "<<endl<<"n : "<<n<<endl<<"m : "<<m<<endl;
}
int main()
{
    int n,m;
    cout<<"Enter the number for swapping : "<<endl;
    cin>>n>>m;
    cout<<"Before swapping : "<<endl<<"n : "<<n<<endl<<"m : "<<m<<endl;
    XOR_Swap(n,m);
    return 0;
}

