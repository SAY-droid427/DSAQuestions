//Code to check if two nodes lie on the same path

#include<bits/stdc++.h>
using namespace std;

int timer=0;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void dfs(vector<int> &previsit, vector<int> &postvisit,vector<int> visited,vector<vector<int>> &adj,int x)
{
    visited[x]=1;

    ++timer;
    previsit[x]=timer;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        dfs(previsit,postvisit,visited,adj,adj[x][i]);

    }
    ++timer;

    postvisit[x]=timer;
}

int query(vector<vector<int>> &adj,int x,int y)
{
    return ((previsit[x]<previsit[y] && postvisit[x]>postvisit[y]) || (previsit[x]>previsit[y] && postvisit[x]<postvisit[y]));

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
    int x,y;
    cin>>x>>y;
    vector<int>previsit(adj.size());
    vector<int>postvisit(adj.size());
    vector<int>visited(adj.size());
    dfs(previsit,postvisit,visited,adj,0);
    cout<<query(adj,x-1,y-1)<<"\n";
}