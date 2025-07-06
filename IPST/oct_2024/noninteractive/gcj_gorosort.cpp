#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  for(int i=1; i<=T; ++i) {
    int n; cin >> n; vector<int> v(n); for(auto &x : v) cin >> x;

    int res = 0;
    for(int i=0; i<n; ++i) if(v[i] != i+1) res ++;
    printf("Case #%d: %d\n", i, res);
  }
  return 0;
}
