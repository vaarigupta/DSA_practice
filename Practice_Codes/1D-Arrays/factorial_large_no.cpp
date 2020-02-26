#include<iostream>
using namespace std;
int multiply(int *output,int x, int size)
{
    int carry =0;
    for(int i=0;i<size;i++)
    {
        int prod = output[i]*x + carry;
        output[i] = prod%10 ;
        carry = prod/10;
    }
    while(carry)
    {
        output[size] = carry%10;
        carry /= 10;
        size++;
    }
    return size;
}
void factorial(int n)
{
    int output[500];
    int size =1;
    output[0] = 1;
    for(int i=2;i<=n;i++)
    {
        size = multiply(output,i,size);
    }
    for(int i= size-1;i>=0;i--)
    {
        cout<<output[i];
    }
    cout<<endl<<"no of digits : " <<size<<endl;
}
int main()
{
    int n;
    cin>>n;
    factorial(n);
    return 0;
}

/*

BROKEN CALCULATOR
Andrew was attempting a mathematics test where he needed to solve problems with factorials. One such problem had an answer which equaled 100! ,
He wondered what would this number look like. He tried to calculate 100! On his scientific calculator but failed to get a correct answer.
Can you write a code to help Andrew calculate factorials of such large numbers?

Input Format:
a single lined integer N

Constraints:
1 < = N < = 500

Output Format
Print the factorial of N

Sample Input
5
Sample Output
120


100
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/
