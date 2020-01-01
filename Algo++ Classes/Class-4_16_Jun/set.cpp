#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    int arr[] = {1,2,4,54,4,6,5,5,60,9};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(set<int>::iterator i=s.begin();i!=s.end();i++)
    {
        cout<<(*i)<<" ";
    }
    return 0;
}
