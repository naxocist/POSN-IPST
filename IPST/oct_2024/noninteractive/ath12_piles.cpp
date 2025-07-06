#include <bits/stdc++.h>
using namespace std;

const int N = 103, mod = 9871;
int C[N][N];
int dp[N];
using pi = pair<int, int>;

void solve() {
  int n, k; cin >> n >> k;

  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i=1; i<k; ++i) dp[i] = 0;

  for(int i=k; i<=n; ++i) {
    cout << "i: " << i << endl;
    for(int j=k; j<=i; ++j) {
      int a = j, b = i-j;
      if(a < b) continue 

      int ways = C[i][j]*dp[i-j];
      dp[i] += ways;
      dp[i] %= mod;
      cout << i << ' ' << j << ' ' << i-j << ' ' << ways << ' ' << C[i][j] << endl;
    }
    cout << endl;
  }

  cout << "RES : ";
  cout << dp[n] << '\n'; 
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  for(int i=0; i<N; ++i) {
    for(int j=0; j<=i; ++j) {
      if(j == 0 or j == i) {
        C[i][j] = 1;
        continue ;
      }
      C[i][j] = C[i-1][j-1] + C[i-1][j];
      C[i][j] %= mod;
    }
  }
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
