#include<iostream>
using namespace std;

///finding max  element in array
int maxElement(int a[], int n)
{
    int maxNum=a[0];
    for(int i=1;i<n;i++)
    {

        if(a[i]>maxNum)
        {
            maxNum = a[i];
        }

    }
    return maxNum;

}
int main()
{
    int n;
    cin>>n;
	int a[100000] = {0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxElement(a,n);
    return 0;
}

