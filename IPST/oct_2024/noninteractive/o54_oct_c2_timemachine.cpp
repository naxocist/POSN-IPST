#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
using pi = pair<int, int>;
#define INF 2e9
#define pb emplace_back

int dt[15][1<<15];
bool vis[15][1<<15];

int dist(pi A, pi B) {
  int a, b, c, d; tie(a, b) = A; tie(c, d) = B;
  return ceil(sqrt((a-c)*(a-c) + (b-d)*(b-d)));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;

  vector<T> points; 
  points.pb(0, 0, 0);
  for(int i=0; i<k; ++i) {
    int x, y, t; cin >> x >> y >> t; 
    points.pb(x, y, t);
  }
  points.pb(n-1, m-1, 0);

  int z = points.size();
  for(int i=0; i<z; ++i) {
    for(int j=0; j<1<<z; ++j) dt[i][j] = INF;
  }

  queue<T> pq;
  dt[0][1] = 0;
  vis[0][1] = 1;

  pq.emplace(0, 0, 1);
  while(pq.size()) {
    int d, u, bt; tie(d, u, bt) = pq.front(); pq.pop();

    for(int v=0; v<z; ++v) {
      if(bt & (1<<v)) continue ;

      int a, b, c, d, e, f; tie(a, b, c) = points[u]; tie(d, e, f) = points[v];
      int g = dist(pi(a, b), pi(d, e));
      int nw = bt | (1<<v);

      if(dt[u][bt] + g - f < dt[v][nw]) {
        dt[v][nw] = dt[u][bt] + g - f;
        pq.emplace(dt[v][nw], v, nw);
      }
    }
  }

  int res = INT_MAX;
  for(int i=0; i<1<<z; ++i) res = min(res, dt[k+1][i]);

  cout << res << '\n';

  return 0;
}
