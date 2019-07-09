#include<iostream>
#include<cstring>
using namespace std;
void substring(char *a)
{
    int n= strlen(a);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                 cout<<a[k];
            }
            cout<<endl;

        }

    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    substring(a);
    return 0;
}
