#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 3;
int n, ar[N], top[N];
queue<int> q[N];

struct node {
  int val, lz = 0, sum;
} seg[4*N];

void push(int i, int l, int r) {
  if(seg[i].lz) {
    seg[i].val += seg[i].lz;
    if(l!=r) seg[2*i].lz += seg[i].lz, seg[2*i+1].lz += seg[i].lz;
    seg[i].lz = 0;
  }
}

node un(node a, node b) {
  node res;
  if(a.val == b.val) {
    res.val = a.val;
    res.sum = a.sum + b.sum;
  }else if(a.val < b.val) res = a;
  else res = b;

  return res;
}

void build(int i = 1, int l = 1, int r = n) {
  if(l == r) {
    seg[i].val = 0;
    seg[i].sum = 1;
    return ;
  }
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

void upd(int a, int b, int x, int i = 1, int l = 1, int r = n) {
  push(i,l,r);
  if(a <= l and r <= b) {
    seg[i].lz += x;
    push(i,l,r);
    return ;
  }
  if(r < a or l > b) return ;
  int md = l + (r-l)/2; 
  upd(a,b,x,2*i,l,md); 
  upd(a,b,x,2*i+1,md+1,r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(int i=1; i<=n; ++i) cin >> ar[i], q[i-1].emplace(0);
  build();

  ll res = 0;
  for(int i=1; i<=n; ++i) {
    int x = ar[i];
    q[x].emplace(i);
    if(q[x].size() == 6) {
      upd(top[x], q[x].front(), -1);
      top[x] = q[x].front() + 1; q[x].pop();
      upd(top[x], q[x].front(), 1);
    }

    int d = n - (seg[1].val == 0 ? seg[1].sum : 0);
    res += n - (seg[1].val == 0 ? seg[1].sum : 0);
  }

  cout << res << '\n';
  return 0;
}
