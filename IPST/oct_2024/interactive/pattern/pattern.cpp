#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb emplace_back
const int N = 2e5 + 3, M = 7, mod = 1e9 + 7;
vector<int> adj[N];
ll dp[N][M];
bool vis[N][M];
int col[N];
ll n, m, cnt;
map<int, int> mp;

ll dfs(int u, int c, int p) {
  if(vis[u][c]) return dp[u][c];
  vis[u][c] = true;

  if(col[u] and col[u] != c) return dp[u][c] = 0;
  
  ll res = 1, sub = 1;
  int ch = 0;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    ch ++;
    ll nw = (m-cnt)*dfs(v,0,u); nw %= mod;
    for(int i=1; i<=cnt; ++i) nw += dfs(v,i,u), nw %= mod;
    res *= nw, res %= mod;
    sub *= nw - dfs(v,c,u) + mod, sub %= mod;
  }

  res = res - sub + mod, res %= mod;

  if(!ch) return dp[u][c] = 1;
  return dp[u][c] = res;
}

int total_pattern(int N, int M, std::vector<std::vector<int> >Path, std::vector<std::vector<int> >p)
{
  n=N,m=M;
  for(auto t : Path) {
    int u = t[0], v = t[1];
    adj[u].pb(v); adj[v].pb(u);
  }

  for(auto t : p) {
    int u = t[0], c = t[1];
    if(!mp[c]) mp[c] = ++cnt;
    col[u] = mp[c];
  }

  ll res = (m-cnt)*dfs(0,0,-1); res %= mod;
  for(int i=1; i<=cnt; ++i) res += dfs(0,i,-1), res %= mod;
  return res;
}
