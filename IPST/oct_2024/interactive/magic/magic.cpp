#include "magic.h"
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using pi = pair<int, int>;
const int N = 2e5 + 3;
vector<pi> adj[N];
int need[N];
bool broke[N];
int n,m;

void dfs(int u) {
  for(auto [v, id] : adj[u]) {
    int c = need[u] + broke[id];
    if(need[v] <= c) continue ;
    need[v] = c;
    dfs(v);
  }
}

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
  vector<int> res;
  n=N,m=M;
  for(int i=0; i<n; ++i) need[i] = 11;
  for(int i=0; i<m; ++i) adj[V[i]].pb(U[i], i);

  for(auto e : q) if(e[0] == 0) broke[e[1]] = true;

  need[0] = 0;
  dfs(0);
  reverse(q.begin(), q.end());
  for(auto e : q) {
    if(e[0] == 0){ 
      int x=e[1];
      broke[x] = false;
      if(need[V[x]] < need[U[x]]) {
        need[U[x]] = need[V[x]];
        dfs(U[x]);
      }
      res.pb(-1);
    }else {
      res.pb(need[e[1]] <= e[2]);
    }
  }

  reverse(res.begin(), res.end());
  return res;
}
