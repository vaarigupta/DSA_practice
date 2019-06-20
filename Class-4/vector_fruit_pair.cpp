#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(pair<string,int> a, pair<string, int> b)
{
    return a.second <b.second;
}
int main()
{
    string fruit[10];
    int n[10];
    vector< pair<string,int> > v;
    pair<string, int> p;
    for(int i=0;i<4;i++)
    {
        cout<<"Enter fruit name and No "<<endl;
        cin>>fruit[i]>>n[i];
         p = make_pair(fruit[i],n[i]);
        v.push_back(p);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    return 0;
}

