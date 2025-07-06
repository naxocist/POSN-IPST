#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;

struct node {
  int cnt = 1, lz = 0, mx = 0;
  bool lf = true, rt = true;
} seg[4*N];

int n;
int ar[N];

node un(node a, node b) {
  node res;
  if(a.mx > b.mx) {
    res = a;
    res.rt = false;
  }
  else if(a.mx < b.mx) {
    res = b;
    res.lf = false;
  }
  else {
    res.cnt = a.cnt + b.cnt;
    if(a.rt and b.lf) res.cnt --;
    res.lf = a.lf;
    res.rt = b.rt;
    res.mx = a.mx;
  }

  res.lz = 0;
  return res;
}

void push(int i, int l, int r) {
  if(seg[i].lz != 0) {
    seg[i].mx += seg[i].lz;
    if(l != r) {
      seg[2*i].lz += seg[i].lz;
      seg[2*i+1].lz += seg[i].lz;
    }
    seg[i].lz = 0;
  }
}

void upd(int a, int b, int k, int i = 1, int l = 1, int r = n) {
  push(i,l,r);
  if(a <= l and r <= b) {
    seg[i].lz += k;
    push(i,l,r);
    return ;
  }
  if(r < a or l > b) return ;
  int md = l + (r-l)/2;
  upd(a,b,k,2*i,l,md); 
  upd(a,b,k,2*i+1,md+1,r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m;
  cin >> n >> m;
  while(m--) {
    int l, r, x; cin >> l >> r >> x;
    upd(l, r, x);
    cout << seg[1].mx << ' ' << seg[1].cnt << '\n';
  }
  return 0;
}
