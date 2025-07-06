#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e5 + 3;
vector<int> adj[N];
int color[N];

bool dfs(int u, int p, int c) {
	show(u)show(c)
	if(color[u] != 0 ) {
		if(color[u] == color[p]) return 0;
		return 1;
	} 

	color[u] = c;
	for(auto v : adj[u]) {
		if(!dfs(v, u, -c)) return 0;
	}
	return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pi> edge;
    for(int i=0; i<m; ++i){
    	int u, v; cin >> u >> v;
    	edge.pb(u, v);
    }

    int l = 1, r = m, res = 1;
    while(l < r) {
    	int md = l+(r-l)/2;
    	show(md)
    	for(int i=1; i<=n; ++i) adj[i].clear(), color[i] = 0;

    	for(int i=0; i<md; ++i) {
    		int u, v; tie(u, v) = edge[i];
    		adj[u].pb(v); adj[v].pb(u);
    	}
    	bool t = dfs(1, 0, 1);
    	// cout << t << endl;x`
    	// for(int i=1; i<=n; ++i) cout << color[i] << ' '; cout << endl;
    	if(t) l = md + 1, res = md;
    	else r = md - 1;
    	// div()
    }
    cout << res;
    return 0;
}
