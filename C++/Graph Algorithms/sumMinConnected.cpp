//Sum of the minimum elements in a graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[w].push_back(v);
    adj[v].push_back(w);
}

void dfs(int x,int a[],int mini,vector<vector<int>> &adj,vector<int> &visited)
{
    mini=min(mini,a[x]);  
    visited[x]=1;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        dfs(adj[x][i],a,mini,adj,visited);
    }      
}

int minSumConnected(vector<vector<int>> &adj,int a[])
{
    vector<int> visited(adj.size(),0);
    int sum=0;
    
    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            int mini=a[i];
            dfs(i,a,mini,adj,visited);
            sum+=mini;
        }
    }

    return sum;

}

int main()
{

    //Here we will also take an array as input which will denote the values of the nodes respectively
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>> adj(vertices,vector<int>());

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }
    
    int a[vertices];
    for(int i=0;i<vertices;i++)
    cin>>a[i];

    cout<<minSumConnected(adj,a)<<"\n";
}
