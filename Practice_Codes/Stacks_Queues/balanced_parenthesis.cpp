/*


BALANCED PARENTHESIS
You are given a string of '(' and ')'. You have to check whether the sequence of parenthesis is balanced or not. For example, "(())", "(())()" are balanced and "())(", "(()))" are not.

Input Format:
A string of '(' , ')' , '{' , '}' and '[' , ']' .

Constraints:
1<=|S|<=10^5

Output Format
Print "Yes" if the parenthesis are balanced and "No" if not balanced.

Sample Input
(())
Sample Output
Yes

*/
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




