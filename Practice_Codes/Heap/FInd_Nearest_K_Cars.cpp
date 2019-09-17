#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class car
{
public:
    int x;
    int y;
    int id;
    car(int id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        return x*x + y*y;

    }
    void print()
    {
        cout<<"ID : "<<id;
        cout<<"=> Location : "<<x<<","<<y<<endl;
    }
};

///functor - functional object - creates object of compareCar internally
///and compare cars on the basis of their distance
class compareCar
{
public:
    bool operator()(car a, car b)
    {
        return a.dist()> b.dist();
    }
};
int main()
{

    priority_queue<car, vector<car> , compareCar> pq;
    int x[] = {1,2,56,23,12,15,10,14};
    int y[] = {0,3,4,5,4,0,6,2};
    int n = sizeof(x)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        car c(i+1,x[i],y[i]);
        pq.push(c);
    }
//    while(!pq.empty())
//    {
//        car c = pq.top();
//        cout<<c.id<<" : Location : "<<c.x<<","<<c.y<<endl;
//        pq.pop();
//    }
        int k;
    cin>>k;
    while(k--)
    {
        car c = pq.top();
        c.print();
        //cout<<c.id<<" : Location : "<<c.x<<","<<c.y<<endl;
        pq.pop();
    }
    return 0;
}

/*

1 : Location : 1,0
2 : Location : 2,3
7 : Location : 10,6
5 : Location : 12,4
8 : Location : 14,2
6 : Location : 15,0
4 : Location : 23,5
3 : Location : 56,4

*/
