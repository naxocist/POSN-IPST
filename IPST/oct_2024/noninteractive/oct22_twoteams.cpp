#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 1e5 + 3;
int color[N];
vector<int> adj[N];

bool dfs(int u, int p, int c) {
  if(color[u]) {
    return color[u] == c;
  }

  color[u] = c;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    if(!dfs(v,u,c==1?2:1)) return false;
  }

  return true;
}

int main() {
  int n, m; cin >> n >> m;

  using pi = pair<int, int>;
  vector<pi> edge;
  while(m--) {
    int u, v; cin >> u >> v;
    edge.pb(u, v);
  }

  int l = -1, r = edge.size();
  while(r - l > 1) {
    int md = l + (r-l)/2;
    for(int i=0; i<=md; ++i) {
      auto [u, v] = edge[i];
      adj[u].pb(v); adj[v].pb(u);
    }
    
    bool ok = true;
    for(int i=1; i<=n; ++i) {
      if(!dfs(i,0,color[i])) {
        ok = false;
        break ;
      }
    }

    if(ok) l = md;
    else r = md;
    for(int i=1; i<=n; ++i) adj[i].clear(), color[i] = 0;
  }

  cout << l+1 << '\n';
  return 0;
}
