#include<iostream>
using namespace std;
void counting_sort(int *a, int n)
{

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
    counting_sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}


