#include<bits/stdc++.h>
using namespace std;

void printChar(char *a, int no)
{
    int i=0;
    while(no>0)
    {
        (no&1)?cout<<a[i]:cout<<"";
        i++;
        no >>= 1;
    }
}
void printSubseq(char *str)
{
    int n = strlen(str);
    int range = (1<<n) - 1;
    for(int i=0;i<=range;i++)
    {
        printChar(str,i);
        cout<<endl;
    }
}
int main()
{
    char str[1000];
    cin>>str;
    printSubseq(str);


    return 0;
}






