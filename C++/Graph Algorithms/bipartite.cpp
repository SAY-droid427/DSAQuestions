#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int bipartite(vector<vector<int>> &adj)
{
    vector<int> color(adj.size());
    for(int i=0;i<adj.size();i++)
    color[i]=-1;

    color[0]=0;
    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int i=0;i<adj[x].size();i++)
        {
            if(color[adj[x][i]]==-1)
            {
               color[adj[x][i]]=1-color[x];
               q.push(adj[x][i]);

            }
            else if(color[adj[x][i]]==color[x])
            return 0;
        }
    }
    return 1;
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

    cout<<bipartite(adj)<<"\n";

}