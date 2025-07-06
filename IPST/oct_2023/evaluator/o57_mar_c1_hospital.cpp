#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> adj[N];
int sub[N], res, n;

int dfs(int u, int p) {
	sub[u] = 1;
	for(auto v : adj[u]) {
		if(v == p) continue ;
		sub[u] += dfs(v, u);
	}
	return sub[u];
}

int centroid(int u, int p) {
	for(auto v : adj[u]) {
		if(v == p) continue ;
		if(sub[v] > n/2) return centroid(v, u);
	}
	return u;
}

void f(int u, int p, int d) {
	res += d;
	for(auto v : adj[u]) {
		if(v == p) continue ;
		f(v, u, d+1);
	}
	return ;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v), adj[v].emplace_back(u);
	}
	dfs(1, 0);
	int c = centroid(1, 0);
	f(c, -1, 0);
	cout << res;
	return 0;
}