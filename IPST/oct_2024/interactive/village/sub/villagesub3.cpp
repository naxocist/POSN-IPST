#include "village.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int n, m;
const int N = 2e5 + 3;
using ll = long long;
using pi = pair<ll, ll>;
vector<pi> adj[N];
multiset<int> has[N];
pair<int, int> node[N];
ll w[N];

void init_village(int N, int M, int Q, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  n = N, m = M;

  for(int i=0; i<M; ++i) {
    int u = U[i], v = V[i]; node[i] = pi(u, v);
    w[i] = W[i];

    adj[u].pb(v, i), adj[v].pb(u, i);
    has[u].insert(i); has[v].insert(i);
  }
}

std::vector<std::vector<int>> move_in(int K, std::vector<int> X, std::vector<int> Y) {

  vector<vector<int>> res(K);
  for(int i=0; i<K; ++i) {
    ll u = X[i], t = Y[i];

    vector<int> gone;
    for(auto id : has[u]) {
      w[id] -= t;
      if(w[id] > 0) continue ;
      res[i].pb(id);
      gone.pb(id);
    }

    for(auto g : gone) {
      int u, v; tie(u, v) = node[g];
      has[u].erase(has[u].find(g));
      has[v].erase(has[v].find(g));
    }
  }

  return res;
}
