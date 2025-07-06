#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e3 + 3;
vector<pi> adj[N];
int n, k;
int dsu[N], res[N];

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void dfs(int u, int p, int r) {
    res[u] = r;
    for(auto e : adj[u]) {
        int v, vw; tie(v, vw) = e;
        if(v == p) continue ;
        dfs(v, u, r+vw);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    
    vector<T> edge;
    for(int i=0; i<k; ++i) {
        for(int j=0; j<k; ++j) {
            int x; cin >> x;
            if(i!=j) edge.pb(x, i, j);
        }
    }
    iota(dsu, dsu+N, 0);
    sort(edge.begin(), edge.end());
    for(auto e : edge) {
        int t, u, v; tie(t, u, v) = e; 
        if(par(u) == par(v)) continue ;
        adj[u].pb(v, t); adj[v].pb(u, t);
        dsu[par(u)] = par(v);
    }

    int st = 0;
    for(int i=0; i<k; ++i) if(adj[i].size() == 1) st = i; 

    dfs(st, st, 0);
    for(int i=0; i<k; ++i) cout << res[i] << '\n';
    return 0;
}
