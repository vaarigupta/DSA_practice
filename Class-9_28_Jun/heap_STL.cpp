#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int a[] = {1,4,5,6,7,-1,5,6,7,8,8,-1,4,5,6,7,3,1,3,6,8,9,-1,3,5,6,8};
    int n = sizeof(a)/sizeof(int);
    priority_queue<int> h;
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int d;
        cin>>d;
        h.push(d);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<h.top()<<" ";
        h.pop();
    }
}
