#include<iostream>
#include<vector>
using namespace std;
template<typename t>
class Stack
{
    vector<t> v;
public:
    bool empty()
    {
        return v.size()==0;
    }
    void push(t d)
    {
        v.push_back(d);
    }
    void pop()
    {
        v.pop_back();
    }
    t top()
    {
        return v[v.size()-1];
    }
};
int main()
{
    int d;
    cin>>d;
    Stack<char> s;
    char n;
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

