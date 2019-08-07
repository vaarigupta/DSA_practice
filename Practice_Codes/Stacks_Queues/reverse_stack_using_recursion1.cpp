#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
void insertAtBottom(stack<int> &s, int topE)
{
    if(s.empty())
    {
        s.push(topE);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtBottom(s,topE);
    s.push(x);

}
void reverseStack(stack<int> &s)
{
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,temp);
}
int main() {
    int n,no;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        s.push(no);
    }
    reverseStack(s);
    print(s);
	return 0;
}
