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
//bool mycompare(string s1, string s2)
//{
////    int l1 = s1.length();
////    int l2 = s2.length();
////    if(substring(s1,s2))
////    {
////        return l2>l1;
////    }
//    return s1<s2;
//
//
//}


int main()
{

    string s1, s2;
    cin>>s1>>s2;
    if(substring(s1,s2))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }

    return 0;
}




