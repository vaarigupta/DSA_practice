#include<iostream>
using namespace std;
void subarrays(int *a, int n)
{
    for(int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++)
        {

            for(int k=i;k<=j;k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    subarrays(a,n);
    return 0;
}

/*

4
1 2 3 4

1
1 2
1 2 3
1 2 3 4
2
2 3
2 3 4
3
3 4
4

*/
