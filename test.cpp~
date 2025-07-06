#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

using pi = pair<int, int>;

const int N = 1e5 + 3;
vector<int> adj[N];

int main() {
	int n, m, p, a, b; cin >> n >> m >> p >> a >> b;

	while(m--) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}


	queue<int> q;
	q.push(b);

	bitset<N> vis;
	vector<int> lvl(n+1);
	while(q.size()) {
		int u = q.front(); q.pop();
		if(vis[u]) continue ;
		vis[u] = 1;
		
		for(auto v :adj[u]) {
			lvl[v] = lvl[u] + 1;
			q.push(v);
		}
	}


	for(int i=0; i<n; ++i) {
		cout << lvl[i] << ' ';
	}

}
