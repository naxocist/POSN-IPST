#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int a[N], b[N];
int dp[N][203];

void solve() {
  int n, K; cin >> n >> K;
  for(int i=1; i<=n; ++i) cin >> a[i] >> b[i];

  int res = INT_MAX;
  for(int i=1; i<=n; ++i) {
    int l = max(100-K, 100-i), r = min(100+i, 100+K);
    for(int k=l; k<=r; ++k) {
      dp[i][k] = 2e9;
      if(k>l+1 or (i>K and k>l)) dp[i][k] = dp[i-1][k-1] + a[i]; 
      if(k<r-1 or (i>K and k<r)) dp[i][k] = min(dp[i][k], dp[i-1][k+1] + b[i]);
      if(i == n) res = min(res, dp[i][k]);
    }
  }

  cout << res << '\n';
  return ;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
