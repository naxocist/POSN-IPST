#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int ar[N];

struct node {
  int mx, pref, suf, sum;
};

struct segtree {
  node t[4*N];

  node un(node a, node b) {
    node res;
    res.sum = a.sum + b.sum;
    res.mx = max({a.mx, b.mx, a.suf + b.pref});
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, a.suf + b.sum);

    return res;
  }

  void build(int i, int l, int r) {
    if(l == r) {
      t[i].mx = t[i].pref = t[i].suf = t[i].sum = ar[l];
      return ;
    }
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i] = un(t[2*i], t[2*i+1]);
  }

  node qry(int i, int l, int r, int a, int b) {
    if(a <= l and r <= b) return t[i];
    if(r < a or l > b) {
      node tmp; tmp.mx = tmp.suf = tmp.pref = tmp.sum = 0;
      return tmp;
    }
    int md = l + (r-l)/2;
    return un(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
  }
} seg;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  seg.build(1,1,n);
  while(q--) {
    int l, r; cin >> l >> r; l = max(l, 0), r = min(r, n-1); l++, r++;
    node res = seg.qry(1,1,n,l,r);
    int mx = max({res.mx, res.suf, res.pref, 0});
    //cout << "RES: ";
    cout << mx << '\n';
  }

  return 0;
}
