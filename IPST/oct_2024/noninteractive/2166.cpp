#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

using ll = long long;
struct node { ll sum, pref; };
const int N = 2e5 + 3;
node seg[4*N];
int ar[N];

node merge(node a, node b) {
  node res;
  res.sum = a.sum + b.sum;
  res.pref = max(a.pref, a.sum + b.pref);
  return res;
}

void build(int i, int l, int r) {
  if(l == r) {
    seg[i].sum = seg[i].pref = ar[l];
    return ;
  }
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = merge(seg[2*i], seg[2*i+1]);
}

void upd(int i, int l, int r, int p, int x) {
  if(l == r) return void(seg[i].sum = seg[i].pref = x);
  int md = l + (r-l)/2;
  if(p <= md) upd(2*i,l,md,p,x);
  else upd(2*i+1,md+1,r,p,x);
  seg[i] = merge(seg[2*i], seg[2*i+1]);
}

node qry(int i, int l, int r, int a, int b) {
  if(a <= l and r <= b) return seg[i];
  if(r < a or l > b) return {0, 0};
  int md = l + (r-l)/2;
  return merge(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];
  build(1,1,n);
  while(q--) {
    int c, a, b; cin >> c >> a >> b;
    if(c == 1) upd(1,1,n,a,b);
    else {
      node res = qry(1,1,n,a,b);
      cout << max({0LL, res.pref}) << ln;
    }
  }
  return 0;
}
