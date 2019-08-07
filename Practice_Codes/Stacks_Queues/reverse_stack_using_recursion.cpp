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
//void reverseStack(stack<int> &s)
//{
//    ///base case
//    if(s.empty())
//    {
//        return;
//    }
//    ///rec case
//    int temp = s.top();
//    s.pop();
//    reverseStack(s);
//    cout<<temp<<endl;
//
//}
void insertAtBottom(stack<int> &s, int num)
{
    ///if stack is empty then simply push element onto stack
    if(s.empty())
    {
        s.push(num);
        return;
    }
    ///save the top element every time in order to push them later
    int x = s.top();
    s.pop();
    ///call function to push elements onto call stack
    insertAtBottom(s,num);
    ///when base case hits, then push each x onto the stack
    s.push(x);
}
void reverseStackRec(stack<int> &s)
{
   if(s.empty())
   {
       return;
   }
   ///save top element
   int temp = s.top();
   s.pop();
   ///call recursion and transfer all the elements in the function call stack
   reverseStackRec(s);
   ///Push the saved element onto stack - at bottom
   insertAtBottom(s,temp);

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
    reverseStackRec(s);
    print(s,n);



    return 0;
}


/*



*/



