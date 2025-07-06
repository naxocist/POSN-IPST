#include <vector>
#include "homework.h"

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ln '\n'

using ll = long long;
using pll = pair<ll, ll>;
const int N = 1e5 + 3;
vector<int> adj[N];
bitset<N> vis;

ll go(ll a, ll b) {
  // return a*t such that a*t >= b 
  return ((b-1)/a + 1) * a;
}

int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B) {
  int n = N;

  vector<ll> s(n), e(n), dv(n), need(n);
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  for(int i=0; i<n; ++i) {
    s[i] = HW[i][0]; e[i] = HW[i][1]; dv[i] = HW[i][2]; need[i] = HW[i][3];

    for(auto prv : B[i]) adj[prv].emplace_back(i);
  }

  for(int i=0; i<n; ++i) {
    if(!need[i]) {
      ll g = go(dv[i], s[i]);
      if(g <= e[i]) pq.emplace(g, i);
    }
  }

  int res = 0;
  while(pq.size()) {
    ll t, u; tie(t, u) = pq.top(); pq.pop();
    if(vis[u]) continue ;
    vis[u] = 1;
    // dbg(t, u);
    res ++;

    for(auto v : adj[u]) {
      if(--need[v] > 0) continue ;
      ll g = go(dv[v], max(s[v], t+1));
      if(g <= e[v]) pq.emplace(g, v);
    }
  }

  return res;
}
