#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 2e5 + 3;
vector<int> adj[N], adj2[N];
int a[N], b[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    int sq = sqrt(n);

    for(int u=1; u<=n; ++u) {
        for(int v : adj[u]) {
            if(adj[v].size() > sq) adj2[u].pb(v);
        }
    }

    int q; cin >> q;
    // O(n*sqrt(n))
    while(q--) {
        char c; cin >> c;
        if(c == 'U') {
            int x, y; cin >> x >> y;
            a[x] += y;
            if(adj[x].size() > sq) b[x] += y;
            else for(auto v : adj[x]) a[v] += y;
        }else {
            int x; cin >> x;
            int res = a[x];
            for(auto v : adj2[x]) res += b[v];
            cout << res << '\n';
        }
    }
    return 0;
}
