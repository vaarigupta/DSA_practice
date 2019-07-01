#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the num : "<<endl;
    cin>>n;
    cout<<"Multiplied by 9 : "<<((n<<3)+n)<<endl;
    cout<<"Multiplied by 12 : "<<((n<<3)+(n<<2))<<endl;
    cout<<"Multiplied by 16 : "<<(n<<4)<<endl;
    cout<<"Multiplied by 11 : "<<(n<<3)+ (n<<1)+ n<<endl;
    cout<<"Multiplied by 15 : "<<(n<<3)+(n<<2)+(n<<1)+n<<endl;


    return 0;
}
