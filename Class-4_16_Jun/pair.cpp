#include<iostream>
using namespace std;
int main()
{
    pair<string,int> p;
    p.first = "Apple";
    p.second = 1;
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    pair<string, int> p2 = make_pair("grapes",90);
    cout<<p2.first<<" "<<endl<<p2.second<<endl;
}
