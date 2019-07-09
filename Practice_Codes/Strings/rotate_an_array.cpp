#include<iostream>
#include<cstring>
using namespace std;

void rotateString(char *a, int k)
{
    int n = strlen(a);
    ///shifting all characters by k
    for(int i=n;i>=0;i--)
    {
        a[i+k] = a[i];
    }
    int j=0;
    n = strlen(a);
    /// copying k elements from last to 1st postion -- rotating them
    for(int i=n-k;i<n;i++)
    {
        a[j] = a[i];
        j++;

    }
    a[n-k] = a[n];
    cout<<a;



}
int main()
{

    char a[100];
    int k;
    cin.getline(a,100);
    cin>>k;
    rotateString(a,k);


    return 0;
}
