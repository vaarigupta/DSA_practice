#include<iostream>
using namespace std;
int calculateSetBitsEff(int n)
{
    ///Time Complexity - O(no of set bits)
    int cnt =0;
    while(n>0)
    {
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}

int calculateSetBits(int n)
{
    /// Time Complexity - O(no of bits)
    int cnt=0;
    while(n>0)
    {
        cnt += (n&1);
        n >>= 1;
    }
    return cnt;

}
int main()
{
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<"Set bits in "<<n<<" : "<<calculateSetBitsEff(n)<<endl;
    return 0;
}


