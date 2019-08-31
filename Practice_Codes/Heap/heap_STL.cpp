#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> p;///by default  - it is a max Heap
    priority_queue<int, vector<int>, greater<int> > pq;
    /// using an inBuilt comparator, I can find out the min element from heap
    /// and can easily create a min heap
    int a[10] = {2,5,10,3,24,1};
    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
