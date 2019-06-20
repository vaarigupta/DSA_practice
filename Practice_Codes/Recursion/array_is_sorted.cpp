#include<iostream>
using namespace std;
bool is_Sorted(int *a, int n)
{

        if(n==1)
        {
            return true;
        }
        if(a[0]<a[1] && is_Sorted(a+1,n-1))
        {
            return true;
        }
        return false;

}
int main()
{
    int n;
    int a[] = {1,2,3,4,10,4,5,6,7};
    n = sizeof(a)/sizeof(int);
    if(is_Sorted(a,n))
    {
         cout<<"Yes sorted "<<endl;
    }
    else
    {
        cout<<"Not sorted "<<endl;
    }

    return 0;
}

