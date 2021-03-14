//Strongly connected components

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
}

void dfs(vector<vector<int>> &adj,vector<int> &visited,stack<int> &Stack,int x)
{
    visited[x]=1;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            visited[adj[x][i]]=1;
            dfs(adj,visited,Stack,adj[x][i]);
        }
    }

    Stack.push(x);
}

vector<vector<int>> reverseEdges(vector<vector<int>> &adj)
{
    vector<vector<int>> rAdj(adj.size(),vector<int>());
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            rAdj[adj[i][j]].push_back(i);
            
        }
    }

    return rAdj;
}

int strongly_connected(vector<vector<int>> &adj)
{
    int res=0;
    stack<int> Stack;

    vector<int> visited(adj.size(),0);

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        dfs(adj,visited,Stack,i);
    }

    //Getting the reversed adj list
    vector<vector<int>> rAdj=reverseEdges(adj);

    //Mark all vertices as not visited for second DFS
    for(int i=0;i<adj.size();i++)
    visited[i]=0;

    //Now process all componenst in order defined by the stack
    while(!Stack.empty())
    {
        int x=Stack.top();
        Stack.pop();

        if(!visited[x])
        {
            stack<int> componentStack;
            dfs(rAdj,visited,componentStack,x);
            res++;
        }
    }

    return res;

}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>> adj;

    for(int i=0;i<vertices;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }

    cout<<strongly_connected(adj)<<"\n";
}