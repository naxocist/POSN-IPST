#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
  int key, pr, cnt, val;
  node *l, *r;
  node(int k): cnt(1), key(k), l(nullptr), r(nullptr), pr(rng()) {}
};

using pnode = node*;

int cnt(pnode u) { return u ? u->cnt : 0; }
void upd_cnt(pnode u) { if(u) u->cnt = cnt(u->l) + cnt(u->r) + 1; }


void split(pnode u, int k, pnode &l, pnode &r) {
  if(!u) return void(l = r = nullptr);
  if(u->key <= k) split(u->r, k, u->r, r), l = u;
  else split(u->l, k, l, u->l), r = u;
  upd_cnt(u);
}


void merge(pnode &u, pnode l, pnode r) {
  if(!l or !r) u = l ? l : r;
  else if(l->pr > r->pr) merge(l->r, l->r, r), u = l;
  else merge(r->l, l, r->l), u = r;
  upd_cnt(u);
} 


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  pnode t;
  return 0;
}
