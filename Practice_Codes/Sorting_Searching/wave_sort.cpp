#include<iostream>
using namespace std;
int main()
{
    int a[100] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i+=2)
    {


            ///Check for left element
            if(a[i]<a[i-1] && i>0)
            {
                swap(a[i],a[i-1]);
            }

            ///Check for right element
            if(a[i+1]>a[i] && i<=(n-2))
            {
                swap(a[i],a[i+1]);
            }


    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

