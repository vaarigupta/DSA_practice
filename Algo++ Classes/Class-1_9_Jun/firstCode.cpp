#include<iostream>
using namespace std;
int main()
{
    int num =365;
    float denom = 365.0;
    int cnt=0;
    float p;
    cin>>p;
    float current_p = 1.0;
    while(current_p >= (1-p))
    {
        current_p  *= num/denom;
        num--;
        cnt++;
        cout<<"prob "<<current_p<<" for people "<<cnt<<endl;
    }
    return 0;
}
