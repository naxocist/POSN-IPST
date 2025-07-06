#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

mt19937 rng(time(0));

struct node {
  int key, pr, cnt;
  node *l, *r;
  node(int k): key(k), pr(rng()), cnt(1), l(nullptr), r(nullptr) {}
};

using pnode = node*;

int cnt(pnode t) { return t ? t->cnt : 0; }
void upd_cnt(pnode t) { if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r); }

void split(pnode u, int k, pnode &l, pnode &r) {
  if(!u) return void(l = r = nullptr);

  if(u->key <= k) split(u->r, k, u->r, r), l = u; 
  else split(u->l, k, l, u->l), r = u;
  upd_cnt(u);
}

// assume max_key(l) < min_key(r)
void merge(pnode &u, pnode l, pnode r) {
  if(!l or !r) u = l ? l : r;
  else if(l->pr > r->pr) merge(l->r, l->r, r), u = l;
  else merge(r->l, l, r->l), u = r;

  upd_cnt(u);
}

bool find(pnode t, int x) {
  if(!t) return false;
  if(t->key == x) return true;

  if(x < t->key) return find(t->l, x);
  return find(t->r, x);
}

void insert(pnode &t, int x) {
  if(find(t, x)) return ;
  pnode lf, rt; split(t, x, lf, rt);

  pnode N = new node(x);
  merge(t, lf, N); 
  merge(t, t, rt);
}

int cnt_less(pnode t, int x) {
  if(!t) return 0;

  if(t->key < x) return 1 + cnt(t->l) + cnt_less(t->r, x);
  return cnt_less(t->l, x);
}

pnode get(pnode t, int x) {
  if(!t) return nullptr;
  int idx = cnt(t->l);
  if(idx == x) return t;

  if(x < idx) return get(t->l, x);
  return get(t->r, x - idx - 1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  pnode t = nullptr;
  int q; cin >> q;
  while(q--) {
    char c; int x; cin >> c >> x;
    if(c == 'I') insert(t, x);
    else if(c == 'O') cout << cnt_less(t, x) << ln;
    else cout << get(t, x)->key << ln;
  }

  return 0;
}
