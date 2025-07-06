#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
const int N = 2e5 + 3, LOG = 19;
int c[N];
vector<int> adj[N], go[N];

int s, a, b;
int dir() {
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}

void dfs(int u, int p) {
	if(u!=p) go[p].pb(u);
	for(int v : adj[u]) {
		if(v == -1) continue ;
		if(c[u] == 2) dfs(v, v);
		else dfs(v, p);
	}
	return ;
}


void f(int u, int d) {
	// cout << u << ' ' << d << ' '<<c[u] << endl;
	if(d <= 0 || c[u] == 0) {
		cout << u << '\n';
		return ;
	}

	if(c[u] == 2) f((dir() ? adj[u][1] : adj[u][0]), d-1);
	else{
		int can = go[u].size();
		if(d <= can) f(go[u][d-1], 0);
		else f(go[u][can-1], d-can);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i=0; i<n; ++i) {
		int l, r; cin >> l >> r;
		adj[i].pb(l), adj[i].pb(r);
		c[i] = (l!=-1) + (r!=-1);
	}
	dfs(0, 0);
	while(q--) {
		int d; cin >> d >> s >> a >> b;
		f(0, d);
	}
	return 0;
}