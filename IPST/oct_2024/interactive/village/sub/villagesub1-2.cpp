#include "village.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int n, m;
const int N = 2e5 + 3;
using ll = long long;
using pi = pair<ll, ll>;
vector<pi> adj[N];
ll w[N];

void init_village(int N, int M, int Q, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  n = N, m = M;

  for(int i=0; i<M; ++i) {
    int u = U[i], v = V[i];
    adj[u].pb(v, i), adj[v].pb(u, i);
    w[i] = W[i];
  }
  //Write your code here
}

std::vector<std::vector<int>> move_in(int K, std::vector<int> X, std::vector<int> Y) {
  vector<vector<int>> res(K);
  for(int i=0; i<K; ++i) {
    ll u = X[i], t = Y[i];
    for(auto [v, id] : adj[u]) {
      bool bye = w[id] > 0 and w[id] - t <= 0;
      if(w[id] > 0) w[id] -= t;
      if(bye) res[i].pb(id);
    }
  }

  return res;
}
