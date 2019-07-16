#include<iostream>
using namespace std;

///finding max  element in array
int maxElement(int a[], int n)
{
    int currNum = 0, maxNum=0;
    for(int i=0;i<n;i++)
    {
        currNum = a[i];
        if(currNum>maxNum)
        {
            maxNum = currNum;
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

