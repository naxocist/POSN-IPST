#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, ll>;
using T = tuple<ll, int, int, int>;
const int N = 8e4 + 1;
vector<pi> adj[N];
bool potion[N], vis[N][9];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l, k; cin >> n >> m >> l >> k;
    for(int i=0; i<m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    for(int i=0; i<l; ++i){
        int x; cin >> x; potion[x] = 1;
    }
    
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 1, 0, 0);
    while(pq.size()) {
        ll d; int u, p, c; tie(d, u, p, c) = pq.top(), pq.pop();
        if(u == n) {
            cout << d;
            return 0 ;
        }

        if(vis[u][c]) continue ;
        vis[u][c] = 1;
        for(auto e : adj[u]) {
            int v; ll vw; tie(v, vw) = e;
            if(potion[u] and u != p and c < k) 
                pq.emplace(d+(vw>>(c+1)), v, u, c+1);
            pq.emplace(d+(vw>>c), v, p, c);
        }
    }
    return 0;
}
