#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void printGraph(vector<int>adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<"The adjacency list of node "<<i;
        for(auto x : adj[i])
        cout<<"-->"<<x;
        cout<<"\n";
    }
}

int main()
{
    int V;
    cin>>V;
    int edges;
    cin>>edges;
    vector<int>adj[V];
    int v1[edges],v2[edges];
    for(int i=0;i<edges;i++)
    {
        cin>>v1[i]>>v2[i];
    }

    for(int i=0;i<edges;i++)
    {
        addEdge(adj,v1[i],v2[i]);
    }


    printGraph(adj,V);
    
}