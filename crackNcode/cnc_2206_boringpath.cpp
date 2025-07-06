#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define pb emplace_back
#define all(x) x.begin(), x.end()
#define ln '\n'

using ll = long long;
using pii = pair<int, int>;
using T = tuple<int, int, int>;
using TT = tuple<int, int, int, int>;
const int N = 1e5 + 3;
int dsu[N], mx[N];
ll res[N];
vector<TT> edges;
vector<T> grp[N];
vector<int> adj[N];

int par(int u) { return (dsu[u] == u ? u : dsu[u] = par(dsu[u])); }

int dfs(int u, int p) {
    int t = mx[u];
    for(auto v : adj[u]) {
        if(v == p) continue ;
        t = max(t, dfs(v, u));
    }

    return t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    iota(dsu, dsu+N, 0);
    int n; cin >> n;
    for(int i=0; i<n; ++i) cin >> mx[i];

    for(int i=0; i<n-1; ++i) { 
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges.pb(w, u, v, i);
    }

    sort(all(edges));
    int p = -1, g = -1;
    for(auto [w, u, v, i] : edges) {
        g += p != w;
        grp[g].pb(i, u, v);
        p = w;
    }

    for(int x=0; x<=g; ++x) {
        for(auto [i, u, v] : grp[x]) {
            u = par(u), v = par(v);
            adj[u].pb(v), adj[v].pb(u);
        }

        for(auto [i, u, v] : grp[x]) {
            u = par(u), v = par(v);
            res[i] = (ll)dfs(u, v) * dfs(v, u);
        }

        for(auto [i, u, v] : grp[x]) {
            u = par(u), v = par(v);
            adj[u].clear(), adj[v].clear();
        }

        for(auto [i, u, v] : grp[x]) {
            u = par(u), v = par(v);
            dsu[v] = u;
            mx[u] = max(mx[u], mx[v]);
        }
    }

    for(int i=0; i<n-1; ++i) cout << res[i] << ln;
    return 0;
}