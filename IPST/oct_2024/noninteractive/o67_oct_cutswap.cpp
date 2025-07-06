#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

mt19937 rng(time(0));

struct node {
  int key, cnt, pr;
  node *l, *r;
  node(int k): key(k), cnt(1), pr(rng()), l(nullptr), r(nullptr) {}
};

using pnode = node*;

int cnt(pnode u) { return u ? u->cnt : 0; }
void upd_cnt(pnode u) { if(u) u->cnt = cnt(u->l) + 1 + cnt(u->r); }

void split(pnode u, int k, pnode &l, pnode &r) {
  if(!u) return void(l = r = nullptr);
  if(cnt(u->l) + 1 <= k) split(u->r, k - cnt(u->l) - 1, u->r, r), l = u; 
  else split(u->l, k, l, u->l), r = u;
  upd_cnt(u);
}

void merge(pnode &u, pnode l, pnode r) {
  if(!l or !r) u = l ? l : r;
  else if(l->pr > r->pr) merge(l->r, l->r, r), u = l;
  else merge(r->l, l, r->l), u = r;
  upd_cnt(u);
}

int get(pnode t, int x) {
  if(!t) return -1;
  int idx = cnt(t->l);
  if(idx == x) return t->key;

  if(x < idx) return get(t->l, x);
  return get(t->r, x - idx - 1);
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  pnode t = nullptr;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    merge(t, t, new node(x));
  }

  while(q--) {
    char c; cin >> c;
    if(c == 'M') {
      int l, r; cin >> l >> r;
      pnode lf, tmp; split(t, l, lf, tmp);
      pnode md, rt; split(tmp, r-l, md, rt);

      merge(rt, rt, md);
      merge(t, rt, lf);
    }else {
      int x; cin >> x;
      cout << get(t, x-1) << ln;
    }
  }
  return 0;
}
