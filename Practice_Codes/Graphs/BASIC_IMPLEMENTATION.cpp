#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
class graph
{
    int v;
    list<int> *l;
    public:
    graph(int v)
    {

        this->v = v;
        /// array of linked list
        l = new list<int>[v];

    }
    void addEdge(int u, int v, bool bidir= true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }

    void printAdjacency()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(int vertice : l[i])
            //    for(int v = l[i].begin() ; v!=l[i].end();v++)
            {
                cout<<vertice<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int src)
    {
        queue<int> q;
        map<int, bool> visited;
        visited[src] = true;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for( int nbr : l[node])
            {
                if(!visited[nbr])
                {
                q.push(nbr);
                visited[nbr] = true;

                }

            }
        }



    }

};
int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(3,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
   // g.addEdge(0,1);
    g.printAdjacency();
    cout<<endl;
    g.bfs(0);

    return 0;
}

/*

0->1,2,
1->0,4,3,
2->0,4,
3->1,4,
4->1,2,3,

*/
