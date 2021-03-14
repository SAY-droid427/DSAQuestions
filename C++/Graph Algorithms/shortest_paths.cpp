#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>> &adj(vertices,edges);

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdges(adj,x-1,y-1);
    }

}