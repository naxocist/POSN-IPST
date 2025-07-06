#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define INF 2e18
using ll = long long;

using pi = pair<ll, ll>;

ll dist(pi a, pi b) {
  return abs(a.first-b.first) + abs(a.second-b.second);
}

const int N = 63;
ll d[N][N];
int main() {
  int k, m; cin >> k >> m;

  int kk = 2 * k;
  for(int i=0; i<kk; ++i) {
    for(int j=0; j<kk; ++j) d[i][j] = INF;
    d[i][i] = 0;
  }

  vector<pi> p;
  for(int i=0; i<k; ++i) {
    int x, y, a, b; cin >> x >> y >> a >> b;
    p.pb(pi(x, y)), p.pb(pi(a, b));

    int u = 2*i, v = 2*i + 1;
    d[u][v] = d[v][u] = 0;
  }

  for(int i=0; i<kk; ++i) {
    for(int j=0; j<kk; ++j) 
      d[i][j] = min(d[i][j], dist(p[i], p[j]));
  }

  for(int h=0; h<kk; ++h) {
    for(int i=0; i<kk; ++i) {
      for(int j=0; j<kk; ++j) {
        if(d[i][h] == INF or d[h][j] == INF) continue ;
        d[i][j] = min(d[i][j], d[i][h] + d[h][j]);
      }
    }
  }

  while(m--) {
    int x, y, a, b; cin >> x >> y >> a >> b;

    pi s = pi(x, y), e = pi(a, b);
    ll res = dist(s, e);
    for(int i=0; i<kk; ++i) {
      for(int j=0; j<kk; ++j) {
        res = min(res, dist(s, p[i]) + d[i][j] + dist(p[j], e));
      }
    }

    cout << res << '\n';
  }
  return 0;
}
