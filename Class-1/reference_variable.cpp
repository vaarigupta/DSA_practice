#include<iostream>
using namespace std;
void fun(int *y)  /// deferencing variable
{
    *y = *y +1; ///if we use normal y then it contains address and changes will be made in the address not in the
                /// value thats why we have used *y to refer to the actual bucket
}

//void fun2(int &z)
//{
//    z = z +1;
//}
void fun(int &z)
{
    z = z +1;
}
int main()
{
    int x = 10;
    fun(&x); /// using pointer
    fun(x); /// using refernce variable
    cout<<x;
    return 0;

}

