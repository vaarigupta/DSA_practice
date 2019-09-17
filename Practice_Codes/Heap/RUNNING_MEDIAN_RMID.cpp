#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;
bool balanceHeap( priority_queue<int> pmax ,priority_queue<int, vector<int> , greater<int> > pmin)
{
    return (pmax.size()== pmin.size());
}
int main()
{
    int no;
    priority_queue<int> pmax;
    priority_queue<int, vector<int> , greater<int> > pmin;
    cin>>no;
    pmax.push(no);
    while(scanf("%d",&no)!=EOF)
    {

        pmin.push(no);
        if(!balanceHeap(pmax,pmin))
        {
            if(pmax.size()<pmin.size())
            {
                int x = pmin.top();
                pmax.push(x);
                pmin.pop();
            }
            else
            {
                int x = pmax.top();
                pmin.push(x);
                pmax.pop();
            }
        }
        if(no== -1)
        {

        }
    }

    return 0;
}



