#include<iostream>
using namespace std;
void insertion_sort(int *a, int n)
{
    int num = 0,j=0;
   for(int i=1;i<n;i++)
   {
       num = a[i];
       for( j= i-1;j>=0 && a[j]>num;j--)
       {
           a[j+1] = a[j];
       }
       a[j+1] = num;
   }
}
int main()
{
    int a[100] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion_sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}


