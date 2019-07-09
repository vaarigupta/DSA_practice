#include<iostream>
using namespace std;
int minSteps(int n)
{
    if(n==0)
    {
        return 0;
    }

    int op1 = minSteps(n-1);
    int op2 = minSteps(n/2);
    int op3 = minSteps(n/3);
    int ans = min(op1,op2)
}
int main()
{

    return 0;
}


