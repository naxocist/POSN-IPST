#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define INF 2e9
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 5e4 + 3;
vector<pi> adj[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<T> edge;
    for(int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edge.pb(u, v, w);
    }    

    int l = 1, r = m, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        for(int i=1; i<=n; ++i) adj[i].clear();
        for(int i=0; i<md; ++i) {
            int u, v,w ; tie(u, v, w) = edge[i];
            adj[u].pb(v, w), adj[v].pb(u, w);
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.emplace(0, 1);
        vector<int> dist(n+1, INF);
        dist[1] = 0;
        while(pq.size()) {
            int d, u; tie(d, u) = pq.top(); pq.pop();
            if(dist[u] < d) continue ;
            for(auto e : adj[u]) {
                int v, vw; tie(v, vw) = e;
                if(dist[u] + vw < dist[v]) {
                    dist[v] = dist[u] + vw;
                    pq.emplace(dist[v], v);
                }
            }
        }

        if(dist[n] <= k) r = md - 1, res = md;
        else l = md + 1;
    }
    cout << res;
    return 0;
}
