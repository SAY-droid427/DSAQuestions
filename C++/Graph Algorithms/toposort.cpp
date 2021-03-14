//Topological sorting

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
}

void dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &order,int x)
{
    visited[x]=1;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
            dfs(adj,visited,order,adj[x][i]);
        
    }
        order.insert(order.begin(),x);

    
}

vector<int> topoSort(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size(),0);
    vector<int> order;

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,order,i);
        }
    }
    return order;
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>> adj(vertices, vector<int>());
    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }

    vector<int> sorted=topoSort(adj);
    for(int i=0;i<sorted.size();i++)
    cout<<sorted[i]+1<<" ";

    

    
}