#include "garden.h"
#include "gardenlib.h"
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define INF 2e9

const int N = 2e5 + 3;
vector<int> adj[N];
int mx[N], mx2[N];
vector<int> g[2*N], rev[2*N];
int d1[2*N], d2[2*N];
bool vis[2*N];
int n, m, p;

int cnt = 0;
bool ok = false;
bool cycle(int u, int root) {
  if(vis[u]) {
    ok = u == root;
    return true;
  }
  cnt ++;
  vis[u] = true;

  for(auto v : g[u]) {
    bool t = cycle(v, root);
    if(t) return true;
  }
  return false;
}

void dfs(int u, int d[]) {
  for(auto v : rev[u]) {
    if(d[v] != -1 and d[u] + 1 >= d[v]) continue ;
    d[v] = d[u] + 1;
    dfs(v, d);
  }
}

// answer (x);
void count_routes(int N, int M, int P, int R[][2], int Q, int G[]) {
  n = N, m = M, p = P;
  memset(mx, -1, sizeof mx);
  memset(mx2, -1, sizeof mx2);
  for(int i=0; i<m; ++i) {
    int u = R[i][0], v = R[i][1];

    if(mx[u] == -1) mx[u] = v;
    else if(mx2[u] == -1) mx2[u] = v;

    if(mx[v] == -1) mx[v] = u;
    else if(mx2[v] == -1) mx2[v] = u;

    adj[u].pb(v), adj[v].pb(u);
  }

  for(int u=0; u<2*n; ++u) {
    if(u < n) {
      // didn't walk through beautiful edge before u
      if(mx[u] == -1) continue ;

      int v = mx[u];
      if(mx[v] == u) v += n;
      g[u].pb(v);
    }else {
      // walked through beautiful edge already before u
      int v = mx2[u - n];
      if(v == -1) v = mx[u - n];
      if(v == -1) continue ;
      if(mx[v] == u - n) v += n;
      g[u].pb(v);
    }
  }

  for(int u=0; u<2*n; ++u) {
    for(int v : g[u]) {
      rev[v].pb(u);
    }
  }

  int q = 0, qq = 0;
  memset(d1, -1, sizeof d1);
  d1[p] = 0;
  dfs(p, d1);
  cycle(p, p);
  if(ok) q = cnt;

  memset(d2, -1, sizeof d2);
  memset(vis, 0, sizeof vis);
  d2[p + n] = 0;
  cnt = 0;
  ok = false;
  dfs(p + n, d2);
  cycle(p + n, p + n);
  if(ok) qq = cnt;

  for(int i=0; i<Q; ++i) {
    int k = G[i], res = 0;
    for(int u=0; u<n; ++u) {
      bool ok = false;
      if(d1[u] != -1 and d1[u] <= k) {
        int len = k - d1[u];
        if(q) ok = len%q==0;
        else ok = len == 0;
      }
      if(d2[u] != -1 and d2[u] <= k) {
        int len = k - d2[u];
        if(qq) ok = len%qq==0 or ok;
        else ok = len == 0 or ok;
      }

      res += ok;
    }
    answer(res);
  }
}


