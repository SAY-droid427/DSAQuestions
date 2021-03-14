//Using previsit and postvisit orders
#include <bits/stdc++.h>
using namespace std;
void addEdges(vector<vector<int>> &adj, int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void dfsUtil(vector<vector<int>> &adj, vector<int> &visited, vector<int> &postvisit, vector<int> &previsit, int x, int timer)
{
    visited[x] = 1;
    timer++;
    previsit[x] = timer;
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
        {
            dfsUtil(adj, visited, postvisit, previsit, adj[x][i], timer);
        }
        ++timer;
        postvisit[x] = timer;
    }
}
void dfs(vector<vector<int>> &adj)
{
    vector<int> postvisit(adj.size());
    vector<int> previsit(adj.size());
    vector<int> visited(adj.size());
    int timer = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            dfsUtil(adj, visited, postvisit, previsit, i, timer);
        }
    }
}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adj(vertices, vector<int>());
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdges(adj, x - 1, y - 1);
    }
    dfs(adj);
}
