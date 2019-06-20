///#include<bits/stdc++.h> ///master header file includes all the libraries
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a>b;
}
int main()
{
    vector<int> v;
    v.reserve(100);///default set size by user
    ///default size = 1
    for(int i=0;i<5;i++)
    {
        v.push_back(100- (i*i));
    }

    ///print
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;
    cout<<"Max Size "<<v.max_size()<<endl;

    sort(v.begin(),v.end(),compare);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)<<" ";
    }

    ///use auto instead of iterator
//    for(auto it=v.begin();it!=v.end();it++)
//    {
//        cout<<(*it)<<" ";
//
//    }


    /// for each loop
//    for(int x:v)
//    {
//        cout<<x<<" ";
//    }
    return 0;
}
