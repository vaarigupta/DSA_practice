#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    int d,n;
    cout<<"Enter elements :"<<endl;
    cin>>d;
    for(int i=0;i<d;i++)
    {
        cin>>n;
        q.push(n);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}


