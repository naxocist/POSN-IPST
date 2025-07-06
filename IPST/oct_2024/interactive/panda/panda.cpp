#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

const int N = 1e5 + 3;
using pi = pair<int,int>
vector<int> adj[N];
int dist[N];
int n, m, s;

void dfs(int u, int p, int d) {
  dist[u] = d;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    int dd = d;
    if(v > s) dd++;
    dfs(v,u,dd);
  }
}

void initialize(int N,int M,int S,std::vector<std::vector<int> >R)
{
  n=N,m=M,s=S;

  for(int i=0; i<M; ++i) {
    int u = R[i][0] , v = R[i][1];
    adj[u].pb(v); adj[v].pb(u);
  }

  dfs(0,-1,0);

}

void panda_spawn(int P,int L,int X)
{
}

void panda_evac(int P,int L,int X)
{
}

int travel(int A,int B)
{
    return 0;
}
