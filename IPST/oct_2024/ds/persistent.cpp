#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int ar[N];
#define np nullptr

struct node {
  int val;
  node *l, *r;

  node(int val): val(val), l(np), r(np) {}
  node(node *a, node *b) {
    l = a, r = b;
    val = a->val + b->val;
  }
};

using pnode = node *;
pnode persist[N];

pnode build(int l, int r) {
  if(l == r) {
    return new node(ar[l]);
  }
  int md = l + (r-l)/2; 
  return new node(build(l,md), build(md+1,r));
}

pnode upd(pnode u, int l, int r, int p, int x) {
  if(l == r) {
    return new node(x);
  }
  int md = l + (r-l)/2;
  if(p <= md) return new node(upd(u->l,l,md,p,x), u->r);
  return new node(u->l, upd(u->r,md+1,r,p,x));
}

int qry(pnode u, int l, int r, int a, int b) {
  if(r < a or l > b) return 0;
  if(a <= l and r <= b) return u->val;
  int md = l + (r-l)/2;
  return qry(u->l,l,md,a,b) + qry(u->r,md+1,r,a,b);
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  int cnt = 1;
  persist[cnt] = build(1,n);

  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int p, x; cin >> p >> x;
      persist[cnt + 1] = upd(persist[cnt],1,n,p,x);
      cnt ++;
    }else {
      int v, l, r; cin >> v >> l >> r;
      cout << qry(persist[v],1,n,l,r) << '\n';
    }
  }
  return 0;
}
