#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool mycompare(pair<string,int> p1, pair<string,int> p2)
{

    if(p1.second == p2.second)
    {
        return p1.first<p2.first;
    }
    return p1.second>p2.second;

}

pair<string,int> p[100005];
long int n;
int main()
{

    int x,k=0,salary;
    string name;
    cin>>x;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>name>>salary;
        if(salary>=x)
        {
            //strcpy(p[k].first,name);
            p[k].first = name;
            p[k].second = salary;
            k++;
        }
    }
    sort(p,p+k,mycompare);
    for(int i=0;i<k;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    return 0;
}


