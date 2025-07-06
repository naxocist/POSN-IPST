#include "highway.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 3;
int n;
using ll = long long;
ll a[N], b[N], c[N];
ll dist[N][N];

void init(int N, int Q, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  n = N;
  for(int i=1; i<n; ++i) a[i] = A[i-1], b[i] = B[i-1], c[i] = C[i-1];

  return;
}

void update(int X, int Y, int Z) {
  X ++;
  a[X] = Y;
  b[X] = Z;
  return;
}

long long query(int S, int T) {
  int s = S, t = T; s++, t++;
  if(s == t) return 0;

  ll res = LLONG_MAX;
  for(int i=1; i<=n; ++i) {
    res = min(res, dist[S][i] + dist[i][T]);
  }

  return min(a[s], b[s] + c[s]);
}
