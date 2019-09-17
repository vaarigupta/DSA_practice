#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int> myMap;
    int a[] = {1,2,3,4,5,0,-1,-2,8,-3};
    int b[] = {2,5,6,7,8,9,10,1};
    int cs=0, inter=0, uni=0;
    int na = sizeof(a)/sizeof(int);
    int nb = sizeof(b)/sizeof(int);
    for(int i=0;i<na;i++)
    {
        myMap[a[i]] = a[i];
        cs++;
    }

    cout<<"Intersection : "<<endl;
    for(int i=0;i<nb;i++)
    {
        if(myMap.count(b[i]))
        {
            cout<<b[i]<<", ";
            inter++;
        }

    }
    cout<<endl;
    for(int i=0;i<nb;i++)
    {
        myMap[b[i]] = b[i];
        cs++;
    }
    cout<<"Union :"<<endl;
    for(auto node: myMap)
    {
        cout<<node.first<<", ";
        uni++;
    }
    int LHS = uni;
    int RHS = cs - inter;
    if(LHS==RHS)
    {
        cout<<endl<<"Successfully implemented :"<<endl;
        cout<<"Union elements "<<uni<<endl;
        cout<<"Intersection elements "<<inter<<endl;
    }


}

