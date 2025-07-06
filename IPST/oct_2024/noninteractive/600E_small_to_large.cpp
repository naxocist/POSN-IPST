#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'

using ll = long long;
using mll = map<ll, ll>;
const int N = 1e5 + 3;
ll res[N], col[N], mxcnt[N];;
vector<int> adj[N];


mll dfs(int u, int p) {

  mll mpu;
  mxcnt[u] = 1;
  mpu[col[u]] = 1;
  res[u] = col[u];

  for(auto v : adj[u]) {
    if(v == p) continue ;
    mll mpv = dfs(v, u);

    if(mpv.size() > mpu.size()) {
      swap(mpu, mpv);
      mxcnt[u] = mxcnt[v];
      res[u] = res[v];
    }

    for(auto [clr, cnt] : mpv) {
      mpu[clr] += cnt;
      if(mpu[clr] > mxcnt[u]) {
        mxcnt[u] = mpu[clr];
        res[u] = clr;
      }else if(mpu[clr] == mxcnt[u]) {
        res[u] += clr;
      }
    }
  }


  return mpu;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) cin >> col[i];

  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  dfs(1, 0);

  for(int i=1; i<=n; ++i) cout << res[i] << ' ';
  return 0;
}
