#include<iostream>
using namespace std;

/*
IS PALINDROME?
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

Input Format:
Enter a number N , add N more numbers

Constraints:
None

Output Format
Display the Boolean result

Sample Input
4
1
2
2
1
Sample Output
true

*/
bool isPalindrome(int *a,int n)
{
    if(n==1 || n==0)
    {
        return true;
    }
    if(a[0]==a[n-1] && (n>0))
    {
        return isPalindrome(a+1,n-2);
    }
    else
    {
         return false;
    }



}
int main() {
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
     if(isPalindrome(a,n))
    {

        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}

