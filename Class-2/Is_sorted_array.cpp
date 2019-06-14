#include<iostream>
using namespace std;
bool isSorted(int *a, int n)
{
    if(n==1)
    {
        return true;
    }
    if((a[0]<a[1]) && isSorted(a+1,n-1))
    {
        return true;

    }
    return false;
}
int main()
{
    int a[] = {1,2,5,6,3,4};
    int n = sizeof(a)/sizeof(int);
    if(isSorted(a,n))
    {
        cout<<"It is sorted"<<endl;
    }
    else
    {
        cout<<"It is not sorted"<<endl;
    }

    return 0;
}


