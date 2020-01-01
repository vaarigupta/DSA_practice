#include<iostream>
using namespace std;
///Generate Balanced parenthesis

void balanced_Parenth(int n,char *output, int open , int close )
{

//    if(n==1)
//    {
//       cout<<"( )";
//    }
//    ///cout<<"(";
//    if(output[j]=='(')
//    {
//        balanced_Parenth(n-1,output[j+1],')')
//    }
//    if(output[j]==')')
//    {
//        balanced_Parenth(n-1,output[j+1],')')
//    }

    if(i == 2*n)
    {
        output[i] = '\0';

    }
    if(close < open)
    {
        output[i] = ')';


    }


}
int main()
{


    return 0;
}

