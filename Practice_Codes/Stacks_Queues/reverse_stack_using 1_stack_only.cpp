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
void transfer (stack<int> &s, stack<int> &r, int n , int k )
{
    for(int i=0;i<(n-1-k);i++)
    {
        r.push(s.top());
        s.pop();
    }
}
void reverseStack(stack<int> &s, stack<int> &r, int n)
{
    for(int k=0;k<n;k++)
    {
        ///save the top element of stack -1
    int temp = s.top();
    s.pop();
    ///transfer the (n-1-k) elements from stack-1 to stack-2
    transfer(s,r,n,k);
    ///push the saved top element onto the stack-1
    s.push(temp);
    ///transfer the (n-k-1) from stack-2 to stack-1
    transfer(r,s,n,k);

    }

}
int main()
{
    stack<int> s,r;
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
    reverseStack(s,r,n);
    print(s,n);



    return 0;
}


/*



*/




