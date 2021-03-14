#include<bits/stdc++.h>
using namespace std ;

#define F first
#define S second
#define inf INT_MAX
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int , int>
#define vpii vector< pii >
#define edge pair< pair <int , int> , int >

const int N = 1e3 + 1 ;
vector<edge> ed(1e4 + 1) ;
vi dis(N , inf) ;
int n , m ;
vb vis (N , false) ;

bool negative_cycle (int s) {
	dis[s] = 0 ;
	for (int i = 0 ; i < n-1 ; ++i) {
		for (int j = 0 ; j < m ; ++j) {
			int a = ed[j].F.F ;
			int b = ed[j].F.S ;
			int c = ed[j].S ;
			if (dis[a] != inf) {
				if (dis[b] > dis[a] + c) {
					dis[b] = dis[a] + c ;
				}
			}
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		int a = ed[i].F.F ;
		int b = ed[i].F.S ;
		int c = ed[i].S ;
		if (dis[a] != inf) {
			if (dis[b] > dis[a] + c) {
				return true ;
			}
		}
	}
	return false ;
}

int main () {
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		cin >> ed[i].F.F >> ed[i].F.S >> ed[i].S ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		if (vis[i] == false) {
			if (negative_cycle(i)) {
				cout << "1\n" ;
				return 0 ;
			}
		}
		for (int i = 1 ; i <= n ; ++i) {
			if (dis[i] != inf) {
				vis[i] = true ;
			}
		}
	}
	cout << "0\n" ;
	return 0 ;
}