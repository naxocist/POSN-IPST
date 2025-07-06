#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define np nullptr
const int N = 3e4 + 3;
int ar[N], sar[N];
int n;
int sn;

int fw[N];

void upd(int i, int v) {
  for(;i<N;i+=i&-i) fw[i] += v;
}

int qry(int i, int s = 0) {
  for(;i>0;i-=i&-i) s += fw[i];
  return s;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;

  set<int> s;
  for(int i=0; i<n; ++i) cin >> ar[i], s.insert(ar[i]);


  int q; cin >> q;
  vector<pair<int, int>> Q[N];
  for(int i=0; i<q; ++i){
    int l, r; cin >> l >> r;
    Q[r].pb(l, i);
  }

  vector<int> res(q);

  map<int, int> nearest;
  for(int r=1; r<=n; ++r) {
    int v = ar[r-1];
    if(nearest.count(v)) {
      upd(nearest[v], -1);
    }

    nearest[v] = r;
    upd(nearest[v], 1);
    for(auto e : Q[r]) {
      int l, x; tie(l, x) = e;
      // query [l, r]
      res[x] = qry(r) - qry(l-1);
    }
  }

  for(auto x : res) cout << x << '\n';
  return 0;
}
