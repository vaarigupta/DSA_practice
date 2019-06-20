#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
class triplet
{
public:
    string name;
    int x,y;

    triplet(string n, int x, int y)
    {
       name = n;
       this->x=x;
       this->y=y;
    }
    int distance ()
    {
        return ((x*x) + (y*y));
    }
};

bool compare (triplet t1, triplet t2)
{
   return t1.distance()> t2.distance();
}
int main()
{
    vector<triplet> v;
    string n;
    int a,b;
    for(int i=0;i<3;i++)
    {
        cin>>n>>a>>b;
        triplet t(n,a,b);
        v.push_back(t);
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].name<<" - "<<v[i].distance();
        cout<<endl;
    }
    return 0;
}
