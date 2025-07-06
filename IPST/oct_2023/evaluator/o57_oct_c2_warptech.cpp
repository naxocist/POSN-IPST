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
const int N = 5003;
int dsu[N];
int sz = 0;

int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
    sz -- ;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;

    int mx = 0, mn = 1e9;
    vector<T> edge;
    for(int i=0; i<m; ++i) {
    	int u, v, w; cin >> u >> v >> w;
    	edge.pb(u, v, w);
    	mx = max(mx, w);
        mn = min(mn, w);
    }

    while(q--) {
    	int d; cin >> d;
    	int l = mn, r = mx, res = 1e9;
    	while(l <= r) {
    		int md = l + (r-l)/2;
    		sz = n;
    		iota(dsu, dsu+n, 0);
    		for(auto e : edge) {
    			int u, v, w; tie(u, v, w) = e;
    			if(w > md) continue  ;
    			un(u, v);
    		}
    		if(sz <= d) r = md - 1, res = min(res, md);
    		else l = md + 1;
    	}

    	cout << res << '\n';
    }
    return 0;
}
