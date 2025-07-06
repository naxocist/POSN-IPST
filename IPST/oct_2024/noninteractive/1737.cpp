#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

using ll = long long;
struct node {
  ll val = 0;
  node *l, *r;
  node(int val): val(val), l(nullptr), r(nullptr) {}
  node(node *ll, node *rr) {
    l = ll, r = rr;
    val = 0;
    if(l) val += ll->val;
    if(r) val += rr->val;
  }
  node(node *u): val(u->val), l(u->l), r(u->r) {}
};

const int N = 2e5 + 3;
using pnode = node*;
pnode per[N];
int ar[N];

pnode build(int l, int r) {
  if(l == r) return new node(ar[l]);
  int md = l + (r-l)/2;
  return new node(build(l,md), build(md+1,r));
}

pnode upd(pnode u, int l, int r, int a, int v) {
  if(l == r) return new node(v);
  int md = l + (r-l)/2;
  if(a <= md) return new node(upd(u->l,l,md,a,v), u->r);
  return new node(u->l, upd(u->r,md+1,r,a,v));
}

ll qry(pnode u, int l, int r, int a, int b) {
  if(a <= l and r <= b) return u->val;
  if(r < a or l > b) return 0;
  int md = l + (r-l)/2;
  return qry(u->l,l,md,a,b) + qry(u->r,md+1,r,a,b);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  int sz = 1;
  per[sz++] = build(1,n);
  while(q--) {
    int c; cin >> c;
    if(c == 1) {
      int k, a, x; cin >> k >> a >> x;
      per[k] = upd(per[k],1,n,a,x);
    } else if(c == 2) {
      int k, l, r; cin >> k >> l >> r;
      cout << qry(per[k],1,n,l,r) << ln;
    }else {
      int x; cin >> x;
      per[sz++] = new node(per[x]);
    }
  }
  return 0;
}
