#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int dp[N][N][3];

int main() {
  int n, m; cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      int x; cin >> x;
      if(i > 1 and j > 1) {
        dp[i][j][0] = max({max(dp[i][j-1][0],dp[i-1][j][0]), max(dp[i-1][j][2],dp[i][j-1][2]), max(dp[i-1][j][1],dp[i][j-1][1])});
        dp[i][j][1] = max(max(dp[i][j-1][0],dp[i-1][j][0])+x, max(dp[i-1][j][1], dp[i][j-1][1]));
        dp[i][j][2] = max(max(dp[i][j-1][1],dp[i-1][j][1])+x, max(dp[i-1][j][2], dp[i][j-1][2]));
      }else if(i > 1) {
        dp[i][j][0] = max({dp[i-1][j][0], dp[i-1][j][2], dp[i-1][j][1]});
        dp[i][j][1] = max(dp[i-1][j][0]+x, dp[i-1][j][1]);
        dp[i][j][2] = max(dp[i-1][j][1]+x, dp[i-1][j][2]);
      }else if(j > 1) {
        dp[i][j][0] = max({dp[i][j-1][0], dp[i][j-1][2], dp[i][j-1][1]});
        dp[i][j][1] = max(dp[i][j-1][0]+x, dp[i][j-1][1]);
        dp[i][j][2] = max(dp[i][j-1][1]+x, dp[i][j-1][2]);
      }else {
        dp[i][j][1] = x;
        dp[i][j][2] = -2e9;
      }
    }
  }

  cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
  return 0;
}
