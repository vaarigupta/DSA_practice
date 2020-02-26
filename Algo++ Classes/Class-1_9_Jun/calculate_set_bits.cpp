#include<iostream>
using namespace std;
/*
count number of 1s in binary representation of an integer

Input Format
Input N = Number of Test Cases, followed by N numbers

Constraints
Output Format
Number of Set Bits in each number each in a new line

Sample Input
3
5
4
15
Sample Output
2
1
4
Explanation
Convert Binary to Decimal first and then count number of 1's present in all digits.

*/
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


