//No. of components
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void explore(vector<vector<int>>&adj, vector<int> &visited,int x)
{
    visited[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        explore(adj,visited,adj[x][i]);
    }
}

int noOfConnected(vector<vector<int>>&adj)
{
    int res=0;
    vector<int> visited(adj.size());

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            explore(adj,visited,i);
            res++;
        }
    }

    return res;
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>> adj(vertices,vector<int>());

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }

    cout<<noOfConnected(adj)<<"\n";
}
