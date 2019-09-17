#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;
void print(priority_queue<int, vector<int> , greater<int> > pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ,";
        pq.pop();
    }
    cout<<endl;
}
int main()
{

    int no;
    int k=3;
    //cin>>k;
    priority_queue<int,vector<int>,greater<int> > pq;
    while(scanf("%d",&no)!=EOF)
    {
        if(no== -1)
        {
            print(pq);
        }
        else if(pq.size()<k)
        {
            pq.push(no);
        }
        else
        {
            if(pq.top()<no)
            {
                pq.pop();
                pq.push(no);
            }
        }


    }
    return 0;
}

