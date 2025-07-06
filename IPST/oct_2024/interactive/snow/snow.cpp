#include "snow.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

const int N = 1e5 + 3;
using pi = pair<int, int>;
int n, m;
vector<pi> adj[N];
vector<int> res;

int f(int x) {
  vector<pi> nw;
  vector<bool> vis(n);

  nw.pb(x,0);
  for(int i=0; i<n; ++i) {
    int u = nw[i].first;
    for(auto [v, d] : adj[u]) {
      if(vis[v]) continue ;
      vis[v] = 1;
      nw.pb(v, d);
    }
  }

  int l = 0, r = n;
  while(r - l > 1) {
    int md = l + (r-l)/2;
    vector<bool> ask(m);
    for(int i=1; i<=md; ++i) ask[nw[i].second] = 1;
    if(road_salt(ask)) r = md;
    else l = md;
  }

  int im = nw[r].first;
  res.pb(im);
  return im;
}

vector<int> find_pair(int N, int M, vector<int>U, vector<int> V){
  n=N,m=M;
  for(int i=0; i<n; ++i) adj[i].clear();
  res.clear();
  for(int i=0; i<m; ++i) {
    int u=U[i], v=V[i];
    adj[u].pb(v, i),adj[v].pb(u, i);
  }
  f(f(0));
  return res;
}
