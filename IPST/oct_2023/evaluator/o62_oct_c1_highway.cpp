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
vector<int> adj[N], rev[N];
bool no[N], st[N], ed[N];

void dfsadj(int u) {
	if(no[u] or st[u]) return ;
	st[u] = 1;
	for(int v : adj[u]) dfsadj(v);
	return ;
}

void dfsrev(int u) {
	if(no[u] or ed[u]) return ;
	ed[u] = 1;
	for(int v : rev[u]) dfsrev(v);
	return ;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, q; cin >> n >> m >> q;
	for(int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
	}  

	vector<pi> Q;
	for(int i=0; i<q; ++i) {
		int x, y; cin >> x >> y;
		if(x == 1) no[y] = 1;
		Q.pb(x, y);
	}

	reverse(all(Q));
	vector<int> res;
	dfsadj(1);
	dfsrev(n);
	for(auto e : Q) {
		int x, y; tie(x, y) = e;
		if(x == 1) {
			no[y] = 0;
			for(int v : adj[y]) {
				if(!no[v] and ed[v]) {
					dfsrev(y);
					break ;
				}
			}

			for(int v : rev[y]) {
				if(!no[v] and st[v]) {
					dfsadj(y);
					break ;
				}
			}
		}else {
			if(!no[y] and st[y] and ed[y]) res.pb(1);
			else res.pb(0);
		}
	}
	reverse(all(res));
	for(auto x : res) cout << x << '\n';
    return 0;
}
