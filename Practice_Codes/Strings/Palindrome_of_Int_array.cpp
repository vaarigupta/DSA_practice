#include<iostream>
using namespace std;
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

