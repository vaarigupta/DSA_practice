#include<iostream>
using namespace std;
int getithBit(int n, int i)
{
   if(n&(1<<i)>=1)
   {
       return 1;
   }
   if(n&(1<<i)==0)
   {
       return 0;
   }
}
int main()
{
    int n,i;
    cout<<"Enter the number and ith Bit :"<<endl;
    cin>>n>>i;
    cout<<"The last Bit : "<<getithBit(n,i)<<endl;

    return 0;
}

