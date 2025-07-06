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
vector<int> group[N];
int sz[N], dsu[N];

int par(int u) {
    return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
    u = par(u), v = par(v);
    if(u == v) return ;
    if(sz[u] > sz[v]) swap(u, v);
    dsu[u] = v;
    for(int s : group[u]) group[v].pb(s);
    sz[v] ++;
}


int qry(int x) {
    vector<int> v = group[par(x)];
    sort(allrev(v));
    int t = lower_bound(allrev(v), x) - v.rbegin();
    return v.size() - t;
}


void solve() {
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        group[i].clear();
        group[i].pb(i), sz[i] = 1, dsu[i] = i;
    }
    while(q--) {
        int k, x, y; cin >> k;
        if(k == 1) cin >> x >> y, un(x, y);
        else cin >> x, cout << qry(x) << '\n';
    }
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
