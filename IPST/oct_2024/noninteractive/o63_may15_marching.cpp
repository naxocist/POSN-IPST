#include <bits/stdc++.h>
using namespace std;

#define INF 2e9
const int N = 1503;
int a[N][N], b[N][N], ar[N][N], aa[N][N], bb[N][N];
int gg[N][N], hh[N][N], tt[N][N], rr[N][N];


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i=0; i<=n+1; ++i) {
    for(int j=0; j<=m+1; ++j) {
      a[i][j] = b[i][j] = aa[i][j] = bb[i][j] = INF;
    }
  }

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      int x; cin >> x; 
      ar[i][j] = x;
      a[i][j] = ar[i][j];
      if(i == 1 and j == 1) continue ;
      a[i][j] += min(a[i-1][j], a[i][j-1]);
    }
  }


  for(int i=n; i>=1; --i) {
    for(int j=1; j<=m; ++j) {
      b[i][j] = ar[i][j];
      if(i == n and j == 1) continue ;
      b[i][j] += min(b[i][j-1], b[i+1][j]);
    }
  }

  for(int i=n; i>=1; --i) {
    for(int j=m; j>=1; --j) {
      aa[i][j] = ar[i][j];
      if(i == n and j == m) continue ;
      aa[i][j] += min(aa[i+1][j], aa[i][j+1]);
    }
  }

  for(int i=1; i<=n; ++i) {
    for(int j=m; j>=1; --j) {
      bb[i][j] = ar[i][j];
      if(i == 1 and j == m) continue ;
      bb[i][j] += min(bb[i-1][j], bb[i][j+1]);
    }
  }

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      gg[i][j] = a[i][j] + b[i][j] - ar[i][j];
      if(j > 1) gg[i][j] = min(gg[i][j], gg[i][j-1] + ar[i][j]);


      hh[i][j] = a[i][j] + bb[i][j] - ar[i][j];
      if(i > 1) hh[i][j] = min(hh[i][j], hh[i-1][j] + ar[i][j]);
    }
  }

  for(int i=n; i>=1; --i) {
    for(int j=m; j>=1; --j) {
      tt[i][j] = aa[i][j] + bb[i][j] - ar[i][j];
      if(j < m) tt[i][j] = min(tt[i][j], tt[i][j+1] + ar[i][j]);

      rr[i][j] = aa[i][j] + b[i][j] - ar[i][j];
      if(i < n) rr[i][j] = min(rr[i][j], rr[i+1][j] + ar[i][j]);
    }
  }

  int res = INF;
  for(int j=1; j<=m; ++j) {
    for(int i=1; i<=n; ++i) {
      res = min({res, gg[i][j] + tt[i][j] - ar[i][j], hh[i][j] + rr[i][j] - ar[i][j]});
    }
  }

  cout << res << '\n';
  return 0;
}
