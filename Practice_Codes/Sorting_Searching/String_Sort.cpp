#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool substring(string s1, string s2)
{
    int i=0;
    int l1 = s1.length() , l2 = s2.length();
    int n = min(l1,l2);
    while(i<n)
    {
        if(s1[i]==s2[i])
            i++;
        else
            return false;
    }

    if(i==n) return true;
}
bool mycompare(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    if(substring(s1,s2))
    {
        return l1>l2;
    }
    return s1<s2;


}


int main()
{

    int n;
    string a[1005];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,mycompare);
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<endl;

    }
    return 0;
}



