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
int dp[N][2], val[N];
vector<int> adj[N];

void dfs(int u, int p) {
    int res = 0;
    for(auto v : adj[u]) {
        if(v == p) continue ;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += val[u];
    return ;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0; i<n; ++i) cin >> val[i];
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }    
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}
