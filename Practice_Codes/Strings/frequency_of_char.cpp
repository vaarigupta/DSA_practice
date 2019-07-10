#include<iostream>
#include<cstring>
using namespace std;

/*
STRINGS-MAX FREQUENCY CHARACTER
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

Input Format:
String

Constraints:
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb
Sample Output
a

*/
char max_freq(char *a)
{
    int n = strlen(a), maxNo=-1,ans=0;
    int freq[256]= {0};
    for(int i=0;i<n;i++)
    {
        int val = a[i] - '\0';
        freq[val]++;
        if(freq[val]>maxNo)
        {
            maxNo = freq[val];
            ans = val;

        }
    }
    return (char)ans;
}
int main()
{
     char a[1000];
    cin.getline(a,1000);
    cout<<max_freq(a);

    return 0;
}
