#include<iostream>
#include<unordered_map>
using namespace std;
class fruit
{
public:
    string name;
    int price;
    float quant;

    fruit()
    {

    }
    fruit(string n, int p, float q)
    {
        name = n;
        price = p;
        quant = q;
    }
};


int main()
{

   unordered_map<string,fruit> m;

   fruit f("Apple",45,23);
   m.insert(make_pair(f.name,f)); /// 1 insertion

   fruit f1("Mango",67,34);
   m[f1.name] = f1;/// 2 insertion

   fruit f2("Grapes",56,12);
   pair<string,fruit> p(f2.name,f2);
   m.insert(p); /// 3 insertion

   for(auto node : m)
   {
       cout<<node.first<<"->"<<node.second.price<<endl;
   }
   cout<<endl;
   m.erase("Apple");
//   for(auto node : m)
//   {
//       cout<<node.first<<"->"<<node.second.price<<endl;
//   }
   for(int i=0;i<m.bucket_count();i++)
   {
       cout<<"Bucket "<<i<<"->";
       for(auto it= m.begin(i);it!=m.end(i);it++)
       {
           cout<<it->first<<","<<it->second.price<<" ";
       }
       cout<<endl;
   }
   cout<<m.count("Apple")<<endl;///searching - returns bool value if found - "1" otherwise - "0"
   cout<<m.count("Mango")<<endl;

    return 0;
}


