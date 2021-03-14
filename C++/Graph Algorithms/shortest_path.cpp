#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int distance(vector<vector<int>> &adj,int x,int y)
{
    if(x==y)
    return 0;

    vector<int>dist(adj.size());
    for(int i=0;i<adj.size();i++)
    dist[i]=INT_MAX;

    queue<int> q;
    dist[x]=0;

    q.push(x);

    while(!q.empty())
    {
        int s=q.front();
        q.pop();

        for(int i=0;i<adj[s].size();i++)
        {
            if(dist[adj[s][i]]==INT_MAX)
            {
                q.push(adj[s][i]);
                dist[adj[s][i]]=dist[s]+1;
            }
        }
    }

    if(dist[y]!=INT_MAX)
    return dist[y];

    return -1;


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
    cout<<distance(adj,x-1,y-1)<<"\n";
}