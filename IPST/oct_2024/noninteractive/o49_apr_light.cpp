#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 3;
int ar[N], tmp[N];

struct segtree {
  struct node {
    int s;
    bool lz;
  } t[4*N];

  void push(int i, int l, int r) {
    if(t[i].lz) {
      t[i].s = ar[r] - ar[l-1] - t[i].s;
      if(l != r) t[2*i].lz = !t[2*i].lz, t[2*i+1].lz = !t[2*i+1].lz;
      t[i].lz = false;
    }
  }
  void build(int i, int l, int r) {
    if(l == r) return void(t[i].s = ar[l] - ar[l-1]);
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i].s = t[2*i].s + t[2*i+1].s;
  }

  void upd(int i, int l, int r, int a, int b) {
    push(i,l,r);
    if(a <= l and r <= b) {
      t[i].lz = true;
      push(i,l,r);
      return ;
    }

    if(r < a or l > b) return ;
    int md = l + (r-l)/2; 
    upd(2*i,l,md,a,b); upd(2*i+1,md+1,r,a,b);
    t[i].s = t[2*i].s + t[2*i+1].s;
  }

} seg;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int L, n; cin >> L >> n;
  for(int i=1; i<=n; ++i) {
    cin >> ar[i]; tmp[i] = ar[i];
  }
  sort(ar+1,ar+1+n);
  unordered_map<int, int> ord;
  for(int i=1; i<=n; ++i) ord[ar[i]] = i;
  ar[n+1] = L;

  seg.build(1,1,n+1);
  for(int i=1; i<=n; ++i) {
    seg.upd(1,1,n+1,ord[tmp[i]]+1, n+1);
    cout << seg.t[1].s << '\n';
  }
  return 0;
}
