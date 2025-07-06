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
const int N = 1e5 + 3;
vector<pi> adj[N], rev[N];
bitset<N> vis, vis2;
int road = 0;
pi um[2*N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l, q; cin >> n >> m >> l >> q;
    for(int i=1; i<=m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v, i);
        rev[v].pb(u, i);
        um[i] = pi(u, v);
    }
    road = m + 1;
    while(q--) {
        int c; cin >> c;
        if(c == 1) {
            int x, y; cin >> x >> y;
            queue<pi> q;
            q.emplace(x, l/2);
            while(q.size()) {
                int u, r; tie(u, r) = q.front(); q.pop();
                if(vis[u]) continue ;
                vis[u] = 1;
                for(auto e : adj[u]) {
                    int v = e.first;
                    if(l) q.emplace(v, l-1);
                }
            }

            q.emplace(y, l - (l/2));
            while(q.size()) {
                int u, r; tie(u, r) = q.front(); q.pop();
                if(vis2[u]) continue ;
                vis2[u] = 1;
                if(vis[u]) {
                    cout << 1 << '\n';
                    goto g;
                }
                for(auto e : rev[u]) {
                    int v = e.first;
                    if(l) q.emplace(v, l-1);
                }
            }
            cout << 0 << '\n';
            g:;
            vis.reset();
            vis2.reset();
        }else if(c == 2) {
            int x; cin >> x;
            int u, v; tie(u, v) = um[x];
            for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
                if((*it).second == x) {
                    adj[u].erase(it); break ;
                }
            }

            for(auto it = rev[v].begin(); it != rev[v].end(); it++) {
                if((*it).second == x) {
                    rev[v].erase(it); break ;
                }
            }
        }else {
            int x, y; cin >> x >> y;
            um[road] = pi(x, y);
            adj[x].pb(y, road);
            rev[y].pb(x, road);
            road ++;
        }
    }
    return 0;
}
