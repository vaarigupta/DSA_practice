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
void reverseStack(stack<int> &s, stack<int> &r, int n)
{
     for(int i=0;i<n;i++)
    {
        r.push(s.top());
        s.pop();
    }
}
int main()
{
    stack<int> s,r1,r2;
    int n,no;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        s.push(no);
    }
    cout<<"Original stack : "<<endl;
   print(s,n);
    reverseStack(s,r1,n);
    reverseStack(r1,r2,n);
    reverseStack(r2,s,n);
    cout<<"Reverse stack : "<<endl;
    print(s,n);


    return 0;
}


/*



*/


