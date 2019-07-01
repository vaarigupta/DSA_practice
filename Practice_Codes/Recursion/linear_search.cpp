#include<iostream>
using namespace std;
///find first occurrence of element
int linear_search(int *a,int n, int key)
{
    if(n==0)
    {
        return -1;
    }
    if(a[0]==key)
    {
        return 0;
    }
    int chotaArray = linear_search(a+1,n-1,key);
    if(chotaArray== -1)
    {
        return -1;
    }
    else
    {
        return 1 + chotaArray;
    }
}

///find last occurrence
int lastocc_LS(int *a, int n , int key)
{
    if(n==0)
    {
        return -1;
    }
    int chotaArr = lastocc_LS(a+1,n-1,key);
    if(chotaArr == -1)
    {
        if(a[0]==key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return chotaArr+1;
}
int main()
{
    int a[] = {1,2,3,4,5,6,6,5,4,4,3};
    int key;
    int n = sizeof(a)/sizeof(int);
    cout<<"Enter key"<<endl;
    cin>>key;
    cout<<"First Occ :"<<linear_search(a,n,key)<<endl;
    cout<<"Last Occ :"<<lastocc_LS(a,n,key);
    return 0;
}
