#include "finallymeet.h"
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using ll = long long;

const int N =3e5 + 3;
vector<int> adj[N];
ll n, m;
int col[N];

ll res,comp,a,b;
bool ok = true;
void dfs(int u, int p, int c) {
  if(col[u]) {
    if(col[u] != c) ok = false;
    return ;
  }
  comp ++;
  if(c == 1) a ++;
  else b ++;

  col[u] = c;

  for(auto v : adj[u]) {
    if(v == p) continue ;
    dfs(v,u,c==1?2:1);
  }
  return ;
}

long long count_init(int N, int M, std::vector<int> U, std::vector<int> V) {
  n = N, m = M;

  for(int i=0; i<m; ++i) {
    int u = U[i], v = V[i];
    adj[u].pb(v), adj[v].pb(u);
  }

  ll res = 0;
  for(int i=0; i<n; ++i) {
    if(col[i]) continue ;

    comp = a = b = 0;
    ok = true;
    dfs(i,-1,1);
    if(!ok) res += comp*comp;
    else res += a*a + b*b;
  }

  return res;
}
