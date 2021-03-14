//Depth first search
#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void explore(vector<vector<int>> &adj,vector<int> &visited,int x)
{
     visited[x]=1;
     for(int i=0;i<adj[x].size();i++)
     {
         if(!visited[adj[x][i]])
         {
             cout<<adj[x][i]+1<<" ";
             explore(adj,visited,adj[x][i]);
         }

     }
}

void traversal(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size());
    
    for(int i=0;i<adj.size();i++)
    {

        if(!visited[i])
        {
            cout<<i+1<<" ";
            explore(adj,visited,i);

        }
    }
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
        addEdges(adj,x-1,y-1);
    }
    traversal(adj);    
}