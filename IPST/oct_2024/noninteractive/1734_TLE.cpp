#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

const int N = 2e5 + 3;
set<int> seg[4*N];
int ar[N];

set<int> un(set<int> a, set<int> b) {
  set<int> ret;
  for(auto x : a) ret.insert(x);
  for(auto x : b) ret.insert(x);
  return ret;
}

void build(int i, int l, int r) {
  if(l == r) {
    seg[i].insert(ar[l]);
    return ;
  }
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

set<int> qry(int i, int l, int r, int a, int b) {
  if(a <= l and r <= b) return seg[i];
  if(r < a or l > b) return set<int>();
  int md = l + (r-l)/2;
  return un(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];
  build(1,1,n);
  while(q--) {
    int l, r; cin >> l >> r;
    cout << qry(1,1,n,l,r).size() << ln;
  }
  return 0;
}
