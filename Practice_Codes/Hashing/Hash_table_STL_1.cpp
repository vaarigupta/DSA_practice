#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;


int main()
{
    unordered_map<string,int> hmap;
    hmap.insert(make_pair("apple",100));
    pair<string,int> p("mango",800);
    hmap.insert(p);
    hmap["banana"] = 400;
    hmap["papaya"] = 250;
    hmap["pineapple"] = 90;
    hmap.erase("papaya");

    ///iterate to all the nodes and print
    for(auto node : hmap)
    {
        cout<<node.first<<" -> "<<node.second<<endl;
    }
    cout<<endl;
    ///Iterate over individual bucket and then iterate over their corresponding linked list
    for(int i=0;i<hmap.bucket_count();i++)
    {
        cout<<"bucket : "<<i;
        for(auto temp=hmap.begin(i);temp!=hmap.end(i);temp++)
        {
            /// it - pointer to each pair of the linked list
            cout<<" "<<temp->first<<"->";
        }
        cout<<endl;
    }
     cout<<hmap.count("papaya");
    return 0;
}

