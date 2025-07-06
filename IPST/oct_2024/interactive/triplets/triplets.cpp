#include "triplets.h"

#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'

using ll = long long;
const ll N = 1e5 + 3, P = 9377;
vector<int> adj[N], rev[N];

int add(int a, int b) { return (a + b)%P; }
int sub(int a, int b) { return (a - b + P)%P; }
int mul(int a, int b) { return ((a%P) * (b%P)) % P; }


bitset<N> vis;
stack<int> st;
void dfs(int u) {
  if(vis[u]) return ;
  vis[u] = 1;

  for(auto v : adj[u]) {
    dfs(v);
  }

  st.emplace(u);
}


stack<int> comp;
void dfs2(int u) {
  if(vis[u]) return ;
  vis[u] = 1;
  for(auto v : rev[u]) {
    dfs2(v);
  }

  comp.emplace(u);
}

ll cal(ll x) {
  if(x < 3) return 0;
  return (((x * (x-1))%P) * (x-2))%P;
}


int count_triplets(int n, std::vector<int> U, std::vector<int> V, std::vector<int> C){

  ll res = cal(n);
  for(int i=0; i<(int)U.size(); ++i) {
    int u = U[i], v = V[i];
    adj[u].pb(v); 
    rev[v].pb(u);
  }

  for(int i=0; i<n; ++i) dfs(i);
  vis.reset();

  while(st.size()) {
    int z = st.top(); st.pop();
    if(vis[z]) continue ;
    dfs2(z);

    map<int, int> col;
    while(comp.size()) {
      int u = comp.top(); comp.pop();
      col[C[u]] ++; 
    }

    for(auto x : col) {
      ll c = x.second;
      res -= cal(c); res += P; res %= P;
    }
  }

  return res;
}
