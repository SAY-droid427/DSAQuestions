////Using breadth first search to check if one vertex is reachable from the other or not
//
//#include<bits/stdc++.h>
//using namespace std;
//
//class Graph
//{
//    int V;
//    list<int>*adj;
//    public:
//    Graph(int V);
//    void addEdge(int v,int w);
//    bool BFS(int d,int s);
//};
//
//Graph::Graph(int V)
//{
//    this->V=V;
//    adj=new list<int>[V];
//}
//
//void Graph::addEdge(int v,int w)
//{
//    adj[v].push_back(w);
//    adj[w].push_back(v);
//}
//
//bool Graph::BFS(int d,int s)
//{
//    if(s==d)
//    return true;
//    bool *visited=new bool[V];
//    for(int i=0;i<V;i++)
//    visited[i]=false;
//
//    list<int> queue;
//    queue.push_back(s);
//
//    list<int>::iterator i;
//    while(!queue.empty())
//    {
//        s=queue.front();
//        queue.pop_front();
//
//        for(i=adj[s].begin();i!=adj[s].end();i++)
//        {
//            if(*i==d)
//            return true;
//
//            if(!visited[*i])
//            {
//                visited[*i]=true;
//                queue.push_back(*i);
//            }
//
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    int vertices,edges;
//    cin>>vertices>>edges;
//    Graph g(vertices);
//    int v1[vertices],v2[vertices];
//    for(int i=0;i<edges;i++)
//    cin>>v1[i]>>v2[i];
//
//    for(int i=0;i<edges;i++)
//    g.addEdge(v1[i]-1,v2[i]-1);
//
//    int s,d;
//    cin>>d>>s;
//
//    if(g.BFS(d-1,s-1))
//    cout<<"1\n";
//    else
//    cout<<"0\n";    
//}

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int explore(vector<vector<int> > &adj, int x, int y, vector<int> &visited) {
	if (x == y) {
		return 1;
	}	
	visited[x] = 1;
	for(int i = 0; i < adj[x].size(); i++) {
		if (!visited[adj[x][i]]) {
			if(explore(adj, adj[x][i], y, visited)) {
				return 1;
			}
		}
	}
	return 0;
}


int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<int> visited(adj.size());
  return explore(adj, x, y, visited);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
	// adjacency list
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}