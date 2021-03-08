//depth first search
#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[20];
 bool isvisited[20];
void addedge( int u,int v)
{
adj[u].push_back(v);
adj[v].push_back(u);
}
void dfs(int node)
{
if(isvisited[node])
return;
else
{
cout<<"visiting node "<<node<<endl;
isvisited[node]=true;
for(auto child:adj[node])
{
dfs(child);}
}
}
int main()
{
addedge(0,1);
addedge(1,3);
addedge(1,4);
addedge(3,2);
addedge(2,4);
addedge(4,5);
addedge(2,6);
dfs(0);
}
