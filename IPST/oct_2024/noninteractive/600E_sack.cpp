#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'

using ll = long long;
const int N = 1e5 + 3;
int sz[N], hv[N], color[N], cnt[N];
ll res[N], sum[N];
vector<int> adj[N], vec[N];

void dfs(int u, int p) {
  sz[u] = 1;
  int mx = 0;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    dfs(v, u);
    sz[u] += sz[v];

    if(sz[v] > mx) {
      mx = sz[v];
      hv[u] = v;
    }
  }
}

void upd(int &mx, int u, int val) {
  sum[cnt[color[u]]] -= color[u];
  cnt[color[u]] += val;
  sum[cnt[color[u]]] += color[u];
  mx = max(mx, cnt[color[u]]);
}


int sack(int u, int p, bool rem) {
  int mx = 0;
  for(auto v : adj[u]){
    if(v != hv[u] and v != p) sack(v, u, true);
  }

  if(sz[u] > 1) {
    mx = max(mx, sack(hv[u], u, false));
    swap(vec[u], vec[hv[u]]);
  }

  vec[u].pb(u);
  upd(mx, u, 1);

  for(auto v : adj[u]){
    if(v != hv[u] and v != p) {
      for(auto x : vec[v]) {
        upd(mx, x, 1);
        vec[u].pb(x);
      }
    }
  }
  
  res[u] = sum[mx];

  if(rem) {
    for(auto v : vec[u]) {
      upd(mx, v, -1);
    }
  }

  return mx;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) cin >> color[i], hv[i] = -1;

  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u].pb(v); adj[v].pb(u);
  }

  dfs(0,-1);
  sack(0,-1,false);

  for(int i=0; i<n; ++i) cout << res[i] << ' ';
  return 0;
}
