#include <bits/stdc++.h>
using namespace std;

using T = tuple<int ,int, int>;
using pi = pair<int, int>;
const int N = 1e5 + 3;
vector<pi> adj[N];
bool vis[N][6];

int main() {

    int n, m, h; scanf("%d%d%d", &n, &m, &h);

    for(int i=0; i<m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].emplace_back(v, w);
    }

    priority_queue<T, vector<T>, greater<T>> pq;

    pq.emplace(0, 1, 0);
    while(pq.size()) {
        int d, u, c; tie(d, u, c) = pq.top(); pq.pop();
        if(vis[u][c]) continue ;
        vis[u][c] = 1;

        // printf("%d %d %d\n", d, u, c);
        if(u == n) {
            printf("%d", d);
            return 0;
        }

        for(auto x : adj[u]) {
            int v = x.first, vw = x.second;
            if(vw >= 0) pq.emplace(d + vw, v, c);

            else if(vw >= -100) pq.emplace(d, v, c);
            else if(c + 1 <= h) pq.emplace(d, v, c+1);
        
        }
    }

    printf("-1");
    return 0;
}

/*
5 6 2
1 2 1
2 3 -200
1 3 5
3 4 2
4 5 -200
3 5 4
*/