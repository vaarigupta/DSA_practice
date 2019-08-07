#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s, int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
void reverseStack(stack<int> &s)
{
    ///base case
    if(s.empty())
    {
        return;
    }
    ///rec case
    int temp = s.top();
    s.pop();
    reverseStack(s);
    cout<<temp<<endl;

}
int main()
{
    stack<int> s;
    int n,no;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        s.push(no);
    }
    cout<<"Original stack : "<<endl;
     print(s,n);
     cout<<"Reverse stack : "<<endl;
    reverseStack(s);



    return 0;
}


/*



*/



