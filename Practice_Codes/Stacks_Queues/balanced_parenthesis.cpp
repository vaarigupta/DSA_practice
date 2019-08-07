#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
void print(stack<int> s, int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
bool checkParenthesis(string a)
{
    stack<char> s;
    for(int i=0;a[i]!='\0';i++)
    {

        if(a[i]=='(' || a[i] =='{' || a[i]=='[')
            {
                s.push(a[i]);
            }
        else if(a[i]==')')
        {
            if(s.empty() || s.top()!='(' )
            {
                return false;
            }
        }
        else if(a[i]=='}' )
        {
            if(s.empty() || s.top()!='{' )
            {
                return false;
            }
        }
        else if( a[i]==']' )
        {
            if(s.empty() || s.top()!='[')
            {
                return false;
            }
        }
        else
        {
            s.pop();
        }

    }
    return s.empty();
}
int main()
{
    string str;
    cin>>str;
    if(checkParenthesis(str))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }




    return 0;
}


/*



*/




