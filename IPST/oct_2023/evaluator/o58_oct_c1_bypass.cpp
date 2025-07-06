#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
using pi = pair<int, int>;
const int N = 1e5 + 3;
vector<int> adj[N];
ll sub[N], mx[N], mx2[N], n, res = 0;

void dfs(int u, int p) {
    sub[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue ;
        dfs(v, u);
        sub[u] += sub[v];
        mx[u] = max(mx[u], sub[v]);
    }   
    
}

int main() {

    scanf("%lld", &n);
    int m = n-1;
    vector<pi> edge;
    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u); 
        edge.emplace_back(u, v);
    }

    dfs(1, -1); 

    for(pi e : edge) {
        int u = e.first, v = e.second;

        if(sub[v] < sub[u]) swap(u, v);

        res = max(res, (n - sub[v]) * mx[u]);
    }
    printf("%lld", res);
    return 0;
}