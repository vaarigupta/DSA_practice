#include<iostream>
#include<cstring>
using namespace std;
bool permutateStr( char* a,char *b)
{
    int freq[27]={0};
    int n1 = strlen(a);
    int n2 = strlen(b);
    if(n1==n2)
    {
    for(int i=0;i<n1;i++)
    {
       int val = a[i] - 'a';
       freq[val]++;
    }
    for(int i=0;i<n2;i++)
    {
        int val = b[i] - 'a';
        freq[val]--;
    }
    int n = sizeof(freq)/sizeof(int);
    int i=0;
    while(freq[i]==0 && i<n)
    {
        i++;
    }
    if(i==n)
    {
        return true;
    }
    }
    return false;




}
int main()
{
    char a[100],b[100];
    cin.getline(a,100);
    cin.getline(b,100);
    if(permutateStr(a,b))
    {
        cout<<"Yes, strings are permutation of each other "<<endl;
    }
    else
    {
        cout<<"No, strings are not  permutation of each other "<<endl;
    }


    return 0;
}

