#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

const int N = 1e5 + 3, M = 1e7 + 3, mod = 33331, LOG = 20;
ll dsu[N], pow2[M], lvl[N], dis[N], up[N][LOG];
vector<pi> adj[N];

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    if(u == v) return ;
    dsu[u] = v;
}

void dfs(int u, int p) {
    if(p != -1) {
        up[u][0] = p;
        for(int i=1; i<LOG; ++i) up[u][i] = up[up[u][i-1]][i-1];
    }
    for(auto e : adj[u]) {
        int v, vw; tie(v, vw) = e;
        if(v == p) continue ;
        lvl[v] = lvl[u] + 1;
        dis[v] = dis[u] + pow2[vw], dis[v] %= mod;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if(lvl[a] < lvl[b]) swap(a, b);
    int d = lvl[a] - lvl[b];
    for(int L=LOG-1; L>=0; --L) 
        if(lvl[up[a][L]] >= lvl[b]) a = up[a][L];
    if(a == b) return a;
    for(int L=LOG-1; L>=0; --L) {
        if(up[a][L] != up[b][L]) {
            a = up[a][L], b = up[b][L];
        }
    }
    return up[a][0];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    pow2[0] = 1;
    for(int i=1; i<=1e7; ++i) pow2[i] = pow2[i-1]*2, pow2[i]%=mod;
    int n, m, q; cin >> n >> m >> q;
    iota(dsu, dsu+N, 0);
    
    vector<T> edge;
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        edge.pb(w, u, v);
    }
    sort(all(edge));
    for(auto e : edge) {
        int w, u, v; tie(w, u, v) = e;
        if(par(u) == par(v)) continue ;
        un(u, v);
        adj[u].pb(v, w), adj[v].pb(u, w);
    }
    dfs(1, 1);
    while(q--) {
        int a, b; cin >> a >> b;
        int l = lca(a, b);
        cout << (((dis[a]+dis[b]-2*dis[l])%mod)+mod)%mod << '\n';
    }
    return 0;
}
