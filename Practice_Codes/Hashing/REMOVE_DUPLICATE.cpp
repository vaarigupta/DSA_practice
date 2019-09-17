#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int> myMap;
    int a[] = {1,2,3,4,5,5,6,3,3,2,2,1,2,3,4,4,5,5};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        myMap[a[i]] = a[i];
    }
    for(auto node: myMap)
    {
        cout<<node.first<<" ";
    }
    return 0;
}
