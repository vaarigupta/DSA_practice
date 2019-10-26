#include<iostream>
using namespace std;
///time complexity - O(no of set bits)
int count_set_bits(int a)
{

    int count = 0;
    while(a>0)
    {
        //cout<<count<<"- "<<a<<" "<<(a-1)<<endl;
        a &= (a-1);
        count++;
    }
    return count;
}
int main()
{
    int a;
    cin>>a;
    cout<<count_set_bits(a);


    return 0;
}


