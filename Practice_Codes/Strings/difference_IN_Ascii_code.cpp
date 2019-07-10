#include<iostream>
#include<cstring>
using namespace std;

/*

STRINGS-DIFFERENCE IN ASCII CODES
Take as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes and print the ans.

Input Format:
String

Constraints:
Length of String should be between 2 to 1000.

Output Format
String

Sample Input
acb
Sample Output
a2c-1b

*/
void asciiCodes(char *a)
{
    int n = strlen(a);
    for(int i=1;i<n;i++)
    {
        char prev = a[i-1];
        int diff = a[i] - a[i-1];
        cout<<prev<<diff;
    }
    cout<<a[n-1];
}
int main()
{
     char a[1000];
    cin.getline(a,1000);
    asciiCodes(a);

    return 0;
}
