#include<iostream>
#include<cstring>
using namespace std;
void reverseStr(char *a)
{
    int n = strlen(a);
    for(int i=0;i<=(n/2);i++)
    {
        swap(a[i],a[n-i-1]);
    }
    cout<<a;

}
int main()
{
    char a[100];
    cin.getline(a,100);
    reverseStr(a);


    return 0;
}
