#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100] = "I - a,m , V,aar,i - G-u-pta";
    char *ptr = strtok(a," ");
    while(ptr!=NULL)
    {
        cout<<ptr<<endl;
        ptr = strtok(NULL," -,");
    }
    return 0;
}
