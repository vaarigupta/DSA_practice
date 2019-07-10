#include<iostream>
#include<cstring>
using namespace std;
/*

CAN YOU READ THIS?
One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in Camel Case. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

Input Format:
A single line contains the string.

Constraints:
|S|<=1000

Output Format
Print words present in the string, in the order in which it appears in the string.

Sample Input
IAmACompetitiveProgrammer
Sample Output
I
Am
A
Competitive
Programmer

*/
void canYouRead(char *a)
{
    int n = strlen(a),temp;
    int upper_a = (int)'A';
    int upper_z = (int)'Z';
    for(int i=0;i<n;i++)
    {
        temp = a[i] - '\0';
        if(upper_a<=a[i] && a[i]<=upper_z)
        {
            cout<<endl;
        }
        cout<<a[i];

    }

}
int main()
{
     char a[1000];
    cin.getline(a,1000);
    canYouRead(a);

    return 0;
}

