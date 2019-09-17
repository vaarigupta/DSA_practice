#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{

    unordered_map<string, int> mymap;
    mymap["Apple"] = 90;
    mymap["Banana"] = 80;
    mymap["Grapes"] = 50;
    mymap["Litchi"] = 60;
    mymap.insert(make_pair("Pear",89)); /// it takes only a pair
    pair<string , int> p("Mango",67);
    mymap.insert(p);
    for(auto node: mymap)
    {
        cout<<node.first<<" "<<node.second<<endl; /// type of auto is also pair
        ///node iterates over the map and print each key and value

    }
    cout<<endl;

    for(int i=0;i<mymap.bucket_count();i++) /// count the no of buckets or table size of the hashTable
    {
        cout<<"Bucket "<<i<<"-> ";
        for(auto it=mymap.begin(i);it!=mymap.end(i);it++)
        {
            ///here 'it' is a pointer to each pair of linked list
            cout<<it->first<<", "<<it->second<<" || ";
        }
        cout<<endl;
    }
    return 0;
}

