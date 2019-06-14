#include<iostream>
using namespace std;
void inc_N(int n)
{
    if(n==0)
    {
        return;
    }
     inc_N(n-1);
    cout<<n<<" ";

}

void dec_N(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    dec_N(n-1);


}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Descending order : "<<endl;
    dec_N(n);
    cout<<endl;
    cout<<"Ascending order : "<<endl;
    inc_N(n);
    return 0;
}

