#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define pb emplace_back

using ll = long long;
const int N = 1e5 + 3;
const int LOG = 18;

int dsu[N];
int dep[N];
int up[N][LOG + 3];
ll ds[N][LOG + 3];

vector<pair<int, ll>> adj[N];

int par(int u) {
	return dsu[u] == u ? u : dsu[u] = par(dsu[u]);
}

void dfs(int u, int p) {
	for(auto [v, w] : adj[u]) {
		if(v == p) continue ;
		dep[v] = dep[u] + 1;
		up[v][0] = u;
		ds[v][0] = w;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);

	int d = dep[u] - dep[v];
	for(int i=0; i<LOG; ++i) {
		if(d & (1<<i)) u = up[u][i];
	}

	if(u == v) return u;

	for(int i=LOG-1; i>=0; --i) {
		if(up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	}

	return up[u][0];
}

ll dist(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);

	ll res = 0;

	int d = dep[u] - dep[v];
	for(int i=0; i<LOG; ++i) {
		if(d & (1<<i)) res += ds[u][i], u = up[u][i];
	}

	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;

	iota(dsu, dsu+N, 0);

	using T = tuple<ll, int, int>;
	vector<T> edge;
	for(int i=0; i<m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge.pb(w, u, v);
	}

	sort(edge.begin(), edge.end());

	for(auto [w, u, v] : edge) {
		int uu = par(u), vv = par(v);
		if(uu == vv) continue ;
		adj[u].pb(v, w), adj[v].pb(u, w);
		dsu[uu] = vv;
	}


	dfs(1, 0);
	for(int i=0; i<LOG; ++i) up[1][i] = 1;

	for(int i=1; i<LOG; ++i) {
		for(int j=1; j<=n; ++j) {
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}

	for(int i=1; i<LOG; ++i) {
		for(int j=1; j<=n; ++j) {
			ds[j][i] = ds[j][i-1] + ds[up[j][i-1]][i-1];
		}
	}


	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;

		int l = lca(u, v);
		cout << dist(u, l) + dist(v, l) << ln;
	}

}

