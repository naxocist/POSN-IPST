#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

void umn(int &a, int b) { a = min(a,b); }
void umx(int &a, int b) { a = max(a,b); }

struct segtree {
  struct node {
    int mx, mn;
  } t[4*N];

  void pull(int i) {
    t[i].mn = min(t[2*i].mn, t[2*i+1].mn);
    t[i].mx = max(t[2*i].mx, t[2*i+1].mx);
  }

  void build(int i, int l, int r) {
    if(l == r) return void(t[i].mn = t[i].mx = l);
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    pull(i);
  }

  void upd(int i, int l, int r, int p, int x) {
    if(l == r) return void(t[i].mn = t[i].mx = x);
    int md = l + (r-l)/2;
    if(p <= md) upd(2*i,l,md,p,x);
    else upd(2*i+1,md+1,r,p,x);
    pull(i);
  }

  int qry(int i, int l, int r, int a, int b, bool ismn) {
    if(a <= l and r <= b) return ismn ? t[i].mn : t[i].mx;
    if(r < a or l > b) return ismn ? 2e9 : -2e9;
    int md = l + (r-l)/2;

    int lf = qry(2*i,l,md,a,b,ismn), rt = qry(2*i+1,md+1,r,a,b,ismn);
    if(ismn) return min(lf, rt);
    return max(lf, rt);
  }

} seg;

int ar[N];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) ar[i] = i;
  seg.build(1,1,n);
  while(q--) {
    int c, l, r; cin >> c >> l >> r; l++,r++;
    if(c == 1) {
      int mn = seg.qry(1,1,n,l,r,true), mx = seg.qry(1,1,n,l,r,false);
      cout << (l == mn and r == mx ? "YES" : "NO") << '\n';
    } else {
      swap(ar[l],ar[r]);
      seg.upd(1,1,n,l,ar[l]);
      seg.upd(1,1,n,r,ar[r]);
    }
  }
  return 0;
}
