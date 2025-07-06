#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 2e5 + 3;
int res[N], col[N];
set<int> d[N];
vector<int> adj[N];

void merge(set<int> &a, set<int> &b) {
  // ensure that each element will be moved less than or equal to log2(N) times -> O(Nlog^2(N));
  if(a.size() < b.size()) swap(a, b);
  for(auto x : b) a.insert(x);
}


void dfs(int u, int p) {

  d[u].insert(col[u]);
  for(auto v : adj[u]) {
    if(v == p) continue ;
    dfs(v, u);
    merge(d[u], d[v]);
  }
  res[u] = d[u].size();
}

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; ++i) cin >> col[i];

  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  dfs(1, 0);

  for(int i=1; i<=n; ++i) {
    cout << res[i] << ' ';
  }
  return 0;
}
