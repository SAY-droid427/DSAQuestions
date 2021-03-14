//Breadth First Search for a graph

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;

    //Pointer to an array containing adjacency lists
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{

    //Mark all the vertices as not visited
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    visited[i]=false;

    //Create a queue for BFS
    list<int> queue;

    //Mark the current node as visited and enqueue it
    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }

}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.BFS(2);
}
