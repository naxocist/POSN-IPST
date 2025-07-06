#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 2e5 + 3;
int seg[4*N], ar[N];

void build(int i, int l, int r) {
  if(l == r) return void(seg[i] = ar[l]);
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = max(seg[2*i], seg[2*i+1]);
}

int qry(int i, int l, int r, int x) {
  if(l == r) return l;
  int md = l + (r-l)/2;
  if(seg[2*i] >= x) return qry(2*i,l,md,x);
  return qry(2*i+1,md+1,r,x);
}

void upd(int i, int l, int r, int p, int x) {
  if(l == r) return void(seg[i] -= x);
  int md = l + (r-l)/2;
  if(p <= md) upd(2*i,l,md,p,x);
  else upd(2*i+1,md+1,r,p,x);
  seg[i] = max(seg[2*i], seg[2*i+1]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i]; build(1,1,n);
  while(q--) {
    int x; cin >> x;
    if(seg[1] < x) {
      cout << 0 << ' ';
      continue ;
    }

    int p = qry(1,1,n,x);
    upd(1,1,n,p,x);
    cout << p << ' ';
  }
  return 0;
}
