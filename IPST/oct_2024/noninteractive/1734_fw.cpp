#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back

const int N = 2e5 + 3;
using pi = pair<int, int>;
int fw[N], ar[N];
vector<pi> Q[N];

void upd(int i, int x) {
  for(;i<N;i+=i&-i) fw[i]+=x;
}

int qry(int i, int s = 0) {
  for(;i>0;i-=i&-i) s+=fw[i];
  return s;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  for(int i=0; i<q; ++i){
    int l, r; cin >> l >> r;
    Q[l].pb(r, i);
  }
  
  unordered_map<int, int> left_most;
  vector<int> res(q);
  for(int i=n; i>=1; --i) {
    if(left_most.count(ar[i])) upd(left_most[ar[i]], -1);
    left_most[ar[i]] = i;
    upd(i, 1);
    for(auto [r, k] : Q[i]) res[k] = qry(r);
  }

  for(auto x : res) cout << x << ln;
  return 0;
}
