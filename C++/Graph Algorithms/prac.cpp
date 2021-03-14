//bfs
#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adj,int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void bfsUtil(vector<vector<int>> &adj,vector<int> &visited,int s)
{
    
    visited[s]=1;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int s=q.front();
        cout<<s+1<<" ";
        q.pop();

        for(int i=0;i<adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                bfsUtil(adj,visited,adj[s][i]);
            }
        }
    }
    
}

void bfs(vector<vector<int>> &adj,int s)
{
    vector<int> visited(adj.size());
    bfsUtil(adj,visited,s);
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
        addEdges(adj,x-1,y-1);
    }

    int s;
    cin>>s;
    bfs(adj,s);
}