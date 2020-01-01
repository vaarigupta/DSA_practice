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

100
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/
