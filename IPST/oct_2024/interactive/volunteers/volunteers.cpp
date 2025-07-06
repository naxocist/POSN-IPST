#include "volunteers.h"
#include <bits/stdc++.h>
using namespace std;

#define INF 2e9
#define all(x) x.begin(), x.end()
const int N = 2e4 + 3;
int n, m;
int dp[N][403], h[N][403];
int pre[N], suf[N];

struct node {
  int val;
  node *l, *r;
  node(int val): val(val), l(nullptr), r(nullptr) {}
} *per[N];

using pnode = node *;

void build(pnode &u, int l = 1, int r = n) {
  u = new node(0);
  if(l == r) return ;
  int md = l + (r-l)/2;
  build(u->l,l,md); build(u->r,md+1,r);
}

void upd(pnode &u, pnode t, int p, int x, int l = 1, int r = n) {
  u = new node(*t);
  u->val = max(u->val, x);
  if(l == r) return ;
  int md = l + (r-l)/2;
  if(p <= md) upd(u->l,t->l,p,x,l,md);
  else upd(u->r,t->r,p,x,md+1,r);
}

int qry(pnode u, int a, int b, int l = 1, int r = n) {
  if(r < a or l > b) return -INF;
  if(a <= l and r <= b) return u->val;
  int md = l + (r-l)/2;
  return max(qry(u->l,a,b,l,md), qry(u->r,a,b,md+1,r));
}


void setup_battalion(int N, int M, int Q, std::vector<std::vector<int>> H) {
  n = N, m = M;

  build(per[0]);
  h[0][1] = INF;
  for(int i=1; i<=n; ++i) {
    sort(all(H[i-1]));
    int mx = 1;
    for(int j=1, k=1; j<=m; ++j) {
      h[i][j] = H[i-1][j-1];
      while(k <= m+1 and h[i-1][k] < h[i][j]) k ++;
      dp[i][j] = dp[i-1][k] + 1;
      mx = max(mx, dp[i][j]);
    }
    int l = i - mx + 1;
    pre[l] = max(pre[l], i);
    suf[i] = l;
    upd(per[i], per[i-1], l, mx); 
  }
  for(int i=1; i<=n; ++i) pre[i] = max(pre[i], pre[i-1]);
  for(int i=n-1; i>=1; --i) suf[i] = min(suf[i], suf[i+1]);
}
int count_volunteers(int L, int R) {
  L++, R++;
  int res = qry(per[R], L, R);
  res = max(res, min(pre[L], R) - L + 1);
  res = max(res, R - max(L, suf[R]) + 1);
  return res;
}
