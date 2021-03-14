//Breadth First Search

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void breadthFirstSearch(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size());

     visited[0]=1;

     queue<int> q;
     
     q.push(0);

     while(!q.empty())
     {
         int x=q.front();
         cout<<x+1<<" ";
         q.pop();

         for(int i=0;i<adj[x].size();i++)
         {
             if(!visited[adj[x][i]])
             {
                 q.push(adj[x][i]);
                 visited[adj[x][i]]=1;
             }

         }
     }
}

int main()
{
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> adj(vertices,vector<int>());

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }

    breadthFirstSearch(adj);
}