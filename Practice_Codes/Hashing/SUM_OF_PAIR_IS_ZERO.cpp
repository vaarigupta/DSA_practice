#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int> myMap;
    int a[] = {1,2,3,4,5,0,-1,-2,8,-3};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        myMap[a[i]] = a[i];
    }
//    for(auto node: myMap)
//    {
//        cout<<node.first<<"-> "<<node.second<<endl;
//    }
    for(int i=0;i<n;i++)
    {
        int first = a[i];
        int second = (-1)*a[i];
        if(myMap.count(second))
        {
            myMap.erase(second);
            myMap.erase(first);
            cout<<first<<","<<second<<endl;
        }
    }
}
