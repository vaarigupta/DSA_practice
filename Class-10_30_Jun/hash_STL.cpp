#include<iostream>
#include<unordered_map>
using namespace std;

///one more STL - map

int main()
{
    unordered_map<string, int> h;
    ///insertion
    ///1st way
    h.insert(make_pair("Apple",20));

    ///2nd way
    pair<string,int> p;
    p.first = "guava";
    p.second = 25;

    h.insert(p);

    ///3rd way
    h["banana"] = 50;
    h.erase("banana");

    ///search
    if(h.count("banana")==0)
    {
        cout<<"Not found "<<endl;
    }
    else
    {
        cout<<h["banana"]<<endl;
    }
    auto ptr = h.find("banana");
    if(ptr==h.end()) /// 1 index more than the no of items in map
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<ptr->first<<"and "<<ptr->second<<endl;
    }

    for(auto p:h)
    {
        cout<<p.first<<" and "<<p.second<<endl;
    }
    h.clear();
    return 0;
}
