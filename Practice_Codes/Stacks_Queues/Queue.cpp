#include<iostream>
using namespace std;
template<typename t>
class Queue
{
    t *a;
    int ms,cs, f, r;
public:
    Queue(int ds = 5)
    {
        ms = ds;
        cs =0;
        f = 0;
        r = ms -1;
        a = new t[ms];
    }
    bool isEmpty()
    {
        return cs==0;
    }
    bool isFull()
    {
        return cs==ms;
    }
    void push(t d)
    {
        if(!isFull())
        {
            r = (r+1)%ms;
            a[r] = d;
            cs++;
            return;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
            f = (f+1)%ms;
            cs--;
            return;
        }
    }
    t getFront()
    {
        return a[f];
    }

};
int main()
{
    Queue<int> q;
    int d,n;
    cout<<"Enter elements :"<<endl;
    cin>>d;
    for(int i=0;i<d;i++)
    {
        cin>>n;
        q.push(n);
    }
    while(!q.isEmpty())
    {
        cout<<q.getFront()<<" ";
        q.pop();
    }

    return 0;
}

