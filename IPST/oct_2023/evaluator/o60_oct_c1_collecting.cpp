#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using t = tuple<int, int, int>;

const int N = 5e4 + 3;
vector<pi> adj[N];
int p[N];
bool vis[N][33];

int main() {

    int n, m, l; scanf("%d%d%d", &n, &m, &l);

    int s, e; scanf("%d%d", &s, &e);

    for(int i=1; i<=n; ++i) scanf("%d", &p[i]);

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
    }

    priority_queue<t, vector<t>, greater<t>> pq;
    pq.emplace(0, 0, s);

    while(pq.size()) {
        int d, c, u; tie(d, c, u) = pq.top(); pq.pop();
        if(vis[u][c]) continue ;
        vis[u][c] = 1;
        if(u == e && c == l) {
            printf("%d", d);
            return 0;
        }

        for(auto x : adj[u]) {
            int v = x.first, vw = x.second;
            if(p[v] != c + 1) pq.emplace(d + vw, c, v);
            else pq.emplace(d + vw, p[v], v);
        }
    }

    printf("-1");
    return 0;
}