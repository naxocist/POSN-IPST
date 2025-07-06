#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

struct fenwick {
  int t[N];

  void upd(int i, int x) {
    for(;i<N;i+=i&-i) t[i] += x;
  }

  int qry(int i, int s = 0) {
    for(;i>0;i-=i&-i) s += t[i];
    return s;
  }
} sum, up, down;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  while(q--) {
    int t, l, r; cin >> t >> l >> r;
    if(t == 1) {
      if(sum.qry(l) == sum.qry(l-1)) up.upd(l,1);
      if(sum.qry(r) == sum.qry(r+1)) down.upd(r+1,1);
      sum.upd(l,1); sum.upd(r+1,-1);
      if(sum.qry(l) == sum.qry(l-1)) down.upd(l,-1);
      if(sum.qry(r) == sum.qry(r+1)) up.upd(r+1,-1);
    }else {
      cout << sum.qry(l) << ' ' << sum.qry(r);

      if(t == 3) cout << ' ' << up.qry(r)-up.qry(l) << ' ' << down.qry(r)-down.qry(l);
      cout << '\n';
    }
  }
  return 0;
}
