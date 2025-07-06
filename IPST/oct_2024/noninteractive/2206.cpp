#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 2e5 + 3;
int ar[N];
int n;

struct segtree {
  int t[4*N];
  bool rev = false;

  void build(int i, int l, int r) {
    if(l == r) {
      t[i] = ar[l] + (rev ? n - l + 1 : l);
      return ;
    }
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i] = min(t[2*i], t[2*i+1]);
  }

  void upd(int i, int l, int r, int p, int x) {
    if(l == r) {
      t[i] = x + (rev ? n - l + 1 : l);
      return ;
    }
    int md = l + (r-l)/2;
    if(p <= md) upd(2*i,l,md,p,x);
    else upd(2*i+1,md+1,r,p,x);
    t[i] = min(t[2*i], t[2*i+1]);
  }

  int qry(int i, int l, int r, int a, int b) {
    if(r < a or l > b) return 2e9;
    if(a <= l and r <= b) return t[i];
    int md = l + (r-l)/2;
    return min(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
  }
} s1, s2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  s2.rev = true;
  s1.build(1,1,n); s2.build(1,1,n);

  while(q--) {
    int c; cin >> c;
    if(c == 1) {
      int k, x; cin >> k >> x;
      s1.upd(1,1,n,k,x); s2.upd(1,1,n,k,x);
    }else {
      int k; cin >> k;
      cout << min(s2.qry(1,1,n,1,k) - n + k - 1, s1.qry(1,1,n,k,n) - k) << ln;
    }
  }
}
