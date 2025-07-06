#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 2e5 + 3;
using ll = long long;
ll ar[N];

struct segtree {
  struct node {
    ll s=0, lz1=0, lz2=0;
  } t[4*N];

  void build(int i, int l, int r) {
    if(l == r) {
      t[i].s = ar[l];
      return; 
    }
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i].s = t[2*i].s + t[2*i+1].s; 
  }

  // apply and compose
  void push(int i, int l, int r) {
    if(t[i].lz1 or t[i].lz2) {
      ll len = r-l+1;
      t[i].s += t[i].lz1*len;
      t[i].s += t[i].lz2*len*(len+1)/2;

      int md = l + (r-l)/2;
      if(l!=r) {
        t[2*i].lz1 += t[i].lz1, t[2*i+1].lz1 += t[i].lz1 + (md + 1 - l)*t[i].lz2;
        t[2*i].lz2+=t[i].lz2,t[2*i+1].lz2+=t[i].lz2;
      }
      t[i].lz1 = t[i].lz2 = 0;
    }
  }

  ll qry(int i, int l, int r, int a, int b) {
    push(i,l,r);
    if(a <= l and r <= b) {
      return t[i].s;
    }
    if(r < a or l > b) return 0;
    int md = l + (r-l)/2; 
    return qry(2*i,l,md,a,b) + qry(2*i+1,md+1,r,a,b);
  }

  void upd(int i, int l, int r, int a, int b) {
    push(i,l,r);
    if(a <= l and r <= b) {
      t[i].lz1 += l-a;
      t[i].lz2 ++;
      push(i,l,r);
      return ;
    }
    if(r < a or l > b) return ;
    int md = l + (r-l)/2; 
    upd(2*i,l,md,a,b), upd(2*i+1,md+1,r,a,b);
    t[i].s = t[2*i].s + t[2*i+1].s;
  }

} seg;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  seg.build(1,1,n);
  while(q--) {
    int c, l, r; cin >> c >> l >> r;
    if(c == 1) seg.upd(1,1,n,l,r);
    else cout << seg.qry(1,1,n,l,r) << ln;
  }
  return 0;
}
