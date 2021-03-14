//Count all possible paths between two vertices

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void countPathsUtil(vector<vector<int>> &adj,int x,int y,int &pathCount)
{
    if(x==y)
    {
        pathCount++;
        cout<<"Counted\n";

    }
    else
    {
        for(int i=0;i<adj[x].size();i++)
        countPathsUtil(adj,adj[x][i],y,pathCount);
    }
    
}

int countPaths(vector<vector<int>> &adj,int x,int y)
{
    int pathCount=0;
    countPathsUtil(adj,x,y,pathCount);
    return pathCount;
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

    cout<<countPaths(adj,x-1,y-1);

}