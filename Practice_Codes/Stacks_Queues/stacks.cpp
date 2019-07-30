#include<iostream>
#include<vector>
using namespace std;
class Stack
{
    vector<int> v;
public:
    bool empty()
    {
        return v.size()==0;
    }
    void push(int d)
    {
        v.push_back(d);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size()-1];
    }
};
int main()
{
    int d,n;
    cin>>d;
    Stack s;
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
