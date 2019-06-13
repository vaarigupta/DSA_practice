#include<iostream>
using namespace std;
bool check_sorted(int *arr, int n)
{
    if(n==1)
    {
        return true;
    }

    if(arr[0]<arr[1] && check_sorted(arr+1,n-1))
    {
        return true;
    }
    return false;



}
int main()
{
   int arr[] = {1,2,3,4,5,6};
   int n = sizeof(arr)/sizeof(int);
   if(check_sorted(arr,n))
   {
       cout<<"Yes sorted "<<endl;
   }
   else
   {
       cout<<"Not sorted"<<endl;
   }
    return 0;
}
