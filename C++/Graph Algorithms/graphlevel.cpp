//Count the number of nodes at agiven level in a tree using breadth first search
#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void level(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size(),0);
    vector<int> level(adj.size(),0);

    level[0]=0;
    visited[0]=0;

    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int i=0;i<adj[x].size();i++)
        {
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]]=1;
                level[adj[x][i]]=level[x]+1;
                q.push(adj[x][i]);
            }
        }
    }

    for(int i=0;i<adj.size();i++)
    {
        cout<<"Level "<<i<<"= "<<level[i]<<"\n";
    }
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>> adj(vertices,vector<int>());

    for(int i=0;i<adj.size();i++)
    {
        int x,y;
        cin>>x>>y;
        addEdges(adj,x-1,y-1);
    }

    level(adj);

}