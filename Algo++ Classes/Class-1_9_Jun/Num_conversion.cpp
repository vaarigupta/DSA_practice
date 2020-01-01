#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the two numbers : "<<endl;
    cin>>n>>m;
    int ans = n^m;
    cout<<"No of bits to be Flipped : "<<__builtin_popcount(ans);
    return 0;
}

