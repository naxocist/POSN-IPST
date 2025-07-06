#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 2e5 + 3;
using ll = long long;
ll seg[4*N], lz[4*N], ar[N];

void push(int i, int l, int r) {
  if(lz[i]) {
    seg[i] += (r-l+1) * lz[i];
    if(l!=r) lz[2*i] += lz[i], lz[2*i+1] += lz[i];
    lz[i] = 0;
  }
}

void build(int i, int l, int r) {
  if(l == r) {
    seg[i] = ar[l];
    return ;
  }
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = seg[2*i] + seg[2*i+1];
}

void upd(int i, int l, int r, int a, int b, int v) {
  push(i,l,r);
  if(a <= l and r <= b) {
    lz[i] += v; push(i,l,r);
    return ;
  }
  if(r < a or l > b) return ;
  int md = l + (r-l)/2;
  upd(2*i,l,md,a,b,v); upd(2*i+1,md+1,r,a,b,v);
}


ll qry(int i, int l, int r, int x) {
  push(i,l,r);
  if(l == r) return seg[i];
  int md = l + (r-l)/2;
  if(x <= md) return qry(2*i,l,md,x);
  return qry(2*i+1,md+1,r,x);
}


int main() {
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> ar[i];
  }
  build(1,1,n);

  while(q--) {
    int c; cin >> c;
    if(c == 1) {
      int a, b, u; cin >> a >> b >> u;
      upd(1,1,n,a,b,u);
    }else {
      int x; cin >> x;
      cout << qry(1,1,n,x) << ln;
    }
  }
  return 0;
}
