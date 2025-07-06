#include <bits/stdc++.h>
using namespace std;

#define INF 2e18;

using ll = long long;
const int N = 2003;
ll dp[N][N], opt[N][N], qs[N];


string res;
void f(int l, int r) {
  if(l == r) {
    cout << res << '\n';
    return ;
  }

  int op = opt[l][r];

  res += '0';
  f(l,op);
  res.pop_back();
  res += '1';
  f(op+1,r);
  res.pop_back();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen ("codes.in","r",stdin);
  freopen ("codes.out","w",stdout);
  int n; cin >> n;

  for(int i=1; i<=n; ++i) cin >> qs[i], qs[i] += qs[i-1];

  for(int len=1; len<=n; ++len) {
    for(int l=1; l<=n; ++l) {
      int r = l + len - 1;
      if(r > n) break ;

      if(len == 1) {
        opt[l][r] = l;
        continue ;
      }

      if(len == 2) {
        dp[l][r] = qs[r] - qs[l-1];
        opt[l][r] = l;
        continue ;
      }

      dp[l][r] = INF;
      for(int k=opt[l][r-1]; k<=opt[l+1][r]; ++k) {
        ll nw = dp[l][k] + dp[k+1][r] + qs[r] - qs[l-1];
        if(nw < dp[l][r]) {
          dp[l][r] = nw;
          opt[l][r] = k;
        }
      }
    }
  }

  f(1, n);
  return 0;
}
