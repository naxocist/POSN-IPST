#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int ar[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, g; cin >> n >> g;
  for(int i=1; i<=n; ++i) cin >> ar[i];

  int res = 1;
  int dp[n+1];
  dp[0] = 0;
  vector<int> lis;
  for(int i=1; i<=n; ++i) {
    auto t = lower_bound(lis.begin(), lis.end(), ar[i]);
    dp[i] = t - lis.begin() + 1;

    if(t == lis.end()) lis.emplace_back(ar[i]);
    else *t = ar[i];

    //cout << dp[i] << " \n"[i == n]; 
  }

  res = lis.size();
  lis.clear();
  for(int i=n; i>=1; --i) {
    int x = lower_bound(lis.begin(), lis.end(), -ar[i] + 2*g) - lis.begin();

    //cout << "I: " << i << " => ";
    //for(auto x : lis) cout << x << ' ';
    //cout << " | " << x << endl;
    res = max(res, dp[i] + x );

    int y = lower_bound(lis.begin(), lis.end(), -ar[i] + g) - lis.begin();
    if(y == lis.size()) lis.emplace_back(-ar[i] + g);
    else lis[y] = -ar[i] + g;
  }

  cout << res << '\n';
  return 0;
}
