#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int d,n;
    cout<<"Enter elements :"<<endl;
    cin>>d;
    stack<int> s;
    for(int i=0;i<d;i++)
    {
       cin>>n;
        s.push(n);
    }

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

