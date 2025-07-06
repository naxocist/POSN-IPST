#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

#define np nullptr
struct node {
  int val;
  node *l = np, *r = np;
  node(int val): val(val) {}
  node(node *a, node *b) {
    l = a, r = b;
    val = a->val + b->val;
  }
} *persist[N];

using pnode = node *;

int n;
int ar[N], sar[N];

pnode build(int l = 1, int r = n) {
  if(l == r) return new node(0);
  int md = l + (r-l)/2;
  return new node(build(l,md), build(md+1,r));
}

pnode upd(pnode u, int p, int l = 1, int r = n) {
  if(l == r) {
    return new node(1);
  }
  int md = l + (r-l)/2;
  if(p <= md) return new node(upd(u->l,p,l,md), u->r);
  return new node(u->l, upd(u->r,p,md+1,r));
} 

int qry(pnode a, pnode b, int x, int l = 1, int r = n) {
  if(l == r) return sar[l-1];
  int md = l + (r-l)/2;
  int lf = a->l->val - b->l->val;
  if(x <= lf) return qry(a->l,b->l,x,l,md);
  return qry(a->r,b->r,x-lf,md+1,r);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> n >> q;
  for(int i=0; i<n; ++i) cin >> ar[i], sar[i] = ar[i];
  sort(sar, sar+n);

  int c = 0;
  persist[0] = build();
  for(int i=0; i<n; ++i) {
    int ord = lower_bound(sar, sar+n, ar[i]) - sar + 1;
    persist[c + 1] = upd(persist[c], ord); c++;
  }

  while(q--) {
    int l, r, x; cin >> l >> r >> x;
    cout << qry(persist[r], persist[l-1], x) << '\n';
  }
  return 0;
}
