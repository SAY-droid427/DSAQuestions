//Checking for a mother vertex
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void dfs(vector<vector<int>> &adj,vector<int> &visited,int x)
{
    visited[x]=1;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            dfs(adj,visited,adj[x][i]);
        }
    }
}

//The mother vertex will be the one which is reached at last

int motherVertex(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size());
    int mv=0;

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,i);
            mv=i;
        }
    }

    for(int i=0;i<adj.size();i++)
    visited[i]=0;

    dfs(adj,visited,mv);

    for(int i=0;i<adj.size();i++)
    {
        if(visited[i]=0)
        return -1;
    }
    return mv+1;
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
    cout<<motherVertex(adj)<<" ";
}