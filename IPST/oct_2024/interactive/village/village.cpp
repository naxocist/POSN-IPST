#include "village.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define INF 2e9
int n, m;
const int N = 2e5 + 3;
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
vector<pi> adj[N];
ll sum[N];
int wg[N];
multiset<pi> threshold[N];
vector<pi> edge;

void init_village(int N, int M, int Q, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  n = N, m = M;
  edge.resize(m);

  for(int i=0; i<m; ++i) {
    int u = U[i], v = V[i], w = W[i]; 
    adj[u].pb(v, i), adj[v].pb(u, i);
    threshold[u].insert(pi((w+1)/2, i));
    threshold[v].insert(pi((w+1)/2, i));

    edge[i] = pi(u, v);
    wg[i] = w;
  }

}

int get_pair(int u, int id) {
  int a, b; tie(a, b) = edge[id];
  return a == u ? b : a;
}

std::vector<std::vector<int>> move_in(int K, std::vector<int> X, std::vector<int> Y) {
  vector<vector<int>> res(K);
  for(int i=0; i<K; ++i) {
    int u = X[i], t = Y[i];
    sum[u] += t;
    vector<T> rem;
    for(auto x : threshold[u]) {
      ll w, id; tie(w, id) = x;
      ll v = get_pair(u, id);
      ll s = sum[u] + sum[v];

      if(s < w) break ;
      rem.pb(w, id, s);
      threshold[v].erase(threshold[v].find(pi(w, id)));
      if(s >= wg[id]) { 
        res[i].pb(id); continue ; 
      }
      ll nw = w;
      while(s >= nw) { nw = nw + (wg[id] - nw + 1)/2; } 
      threshold[v].insert(pi(nw, id));
    }

    for(auto r : rem) {
      ll w, id, s; tie(w, id, s) = r;
      threshold[u].erase(threshold[u].find(pi(w, id)));
      if(s >= wg[id]) continue ;
      ll nw = w;
      while(s >= nw) { nw = nw + (wg[id] - nw + 1)/2; } 
      threshold[u].insert(pi(nw, id));
    }
  }

  return res;
}
