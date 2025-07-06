#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 5e3 + 3;
using pi = pair<int, int>;
vector<int> adj[N], rev[N];
int val[N], lvl[N];
stack<int> st;
bitset<N> vis;

void dfs(int u) {
  if(vis[u]) return ;
  vis[u] = 1;
  for(auto v : adj[u]) dfs(v);
  st.emplace(u);
}

int id = 1;
void dfs2(int u) {
  if(vis[u]) return ;
  vis[u] = 1;
  val[u] = id;
  for(auto v : rev[u]) {
    dfs2(v);
  }
}

void dfs3(int u, int lv) {
  if(lvl[u] >= lv) return ;

  lvl[u] = max(lvl[u], lv);
  for(auto v : adj[u]) {
    dfs3(v, lv+(val[u] != val[v]));
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, p; cin >> n >> p;

  while(p--) {
    int u, v; cin >> u >> v; u++, v++;
    adj[u].pb(v); rev[v].pb(u);
  }

  for(int i=1; i<=n; ++i) dfs(i);
  vis.reset();

  vector<int> ord;
  while(st.size()) {
    int u = st.top(); st.pop();
    if(vis[u]) continue ;
    dfs2(u);
    ord.pb(u);
    id++;
  }

  vis.reset();
  memset(lvl, -1, sizeof lvl);
  for(auto u : ord) {
    if(lvl[u] != -1) continue ;
    dfs3(u,0);
  }

  map<int, int> res;
  for(int i=1; i<=n; ++i) res[lvl[i]] ++;
  for(auto [a, b] : res) {
    cout << b << ' ';
  }
  return 0;
}
