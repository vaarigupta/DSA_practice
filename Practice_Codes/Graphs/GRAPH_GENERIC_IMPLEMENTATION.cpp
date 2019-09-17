#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template <typename T>
class graph
{
    map<T, list<T> > m;
public:
    graph()
    {

    }
    void addEdge(T u, T v, bool bidir = true)
    {
        m[u].push_back(v);
        if(bidir)
        {
            m[v].push_back(u);
        }

    }
    void printAdjacencyList()
    {

        for(auto i: m)
        {
            cout<<i.first<<"-> ";
            for(auto node : i.second)
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto temp : m[node])
            {
                if(!visited[temp])
                {
                    q.push(temp);
                    visited[temp] = true;
                }

            }
        }
    }
};
int main()
{
    graph<string> g;
    g.addEdge("apple","mango");
    g.addEdge("apple","grapes");
    g.addEdge("apple","banana");
    g.addEdge("banana","mango");
    g.addEdge("grapes","mango");
    g.printAdjacencyList();
    g.bfs("apple");
    return 0;
}
