#include<iostream>
#include<cstring>
using namespace std;
///Find Subsequence of string by bitmasking
void generateSubseq(char *a, int i)
{
    int j =0;
    while(i>0)
    {
        if(i&1)
        {
            cout<<a[j];
        }
        i >>= 1;
        j++;
    }

}
void printSubsequence(char *a)
{
    int n = strlen(a);
    for(int i=0;i<(1<<n);i++)
    {
        generateSubseq(a,i);
        cout<<endl;
    }
}

int main()
{
    char ch[] = "vaari";
    printSubsequence(ch);


    return 0;
}

