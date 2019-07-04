#include<iostream>
#include<unordered_map>
using namespace std;
class Fruit
{
public:
    string name;
    float price;
    int qty;

    Fruit()
    {

    }
    Fruit(string n, float p, int q)
    {
        name =n;
        price =p;
        qty = q;
    }

};
int main()
{
//    unordered_map<string, int> m;
//    m["apple"] = 90;
//    m["mango"] = 70;
//    m["banana"] = 50;
//    m["grapes"] = 40;
//    m["cherry"] = 30;
//    for(auto bucket:m)
//    {
//        cout<<bucket.first<<" ,"<<bucket.second<<endl;
//    }
//    cout<<endl;
//    pair<string, int> p("Litchi",20);
//    m.insert(p);
//    for(auto bucket:m)
//    {
//        cout<<bucket.first<<" ,"<<bucket.second<<endl;
//    }
//    cout<<endl;
//    m.insert(make_pair("stawberry",35));
//    for(auto bucket:m)
//    {
//        cout<<bucket.first<<" ,"<<bucket.second<<endl;
//    }

    unordered_map<string, Fruit> mf;
    Fruit f("Apple",67,3);
    mf[f.name] = f;
   // Fruit fs = mf[f.name];
//    cout<<"Name :"<<fs.name<<endl;
//    cout<<"Price :"<<fs.price<<endl;
//    cout<<"Quantity :"<<fs.qty<<endl;

    for(auto bucket: mf)
    {
        cout<<bucket.first<<"->"<<(bucket.second).price;
    }
    cout<<endl;
    //cout<<"Count of Apple : "<<mf.count("Apple")<<endl;
    //cout<<"Countof Mango : "<<mf.count("Apple1")<<endl;
    string key;
    cout<<"Enter key :"<<endl;
    cin>>key;
    if(mf.count(key))
    {
        cout<<"Hurray !!!!  Found the given key"<<endl;
        cout<<"Price is"<<mf[key].price;
    }
    else
    {
        cout<<"Not found "<<endl;
    }
    cout<<endl;
    mf.erase("Apple");
    cout<<"Count of Apple : "<<mf.count("Apple")<<endl;

//    cout<<"Name :"<<f.name<<endl;
//    cout<<"Price :"<<f.price<<endl;
//    cout<<"Quantity :"<<f.qty<<endl;

    return 0;
}
