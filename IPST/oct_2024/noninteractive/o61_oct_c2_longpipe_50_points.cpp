#include<bits/stdc++.h>
using namespace std;
#define int long long
int k=1e9+7;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int qsum[n+5];
    int dp[n+5][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    qsum[0] = 1;

    for(int i=1;i<=n+1;i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1]; 
        if(i-2>=0) dp[i][0] += qsum[i-2];
        dp[i][0] %= k;
        dp[i][1] = 2*dp[i-1][0] + dp[i-1][1];
        dp[i][1] %= k;
        qsum[i] = qsum[i-1] + dp[i][0];
        qsum[i] %= k;
    }
    for(int i=1; i<=n+1; ++i) cout << dp[i][1] << ' '; cout << endl;
    cout << dp[n+1][1];
    return 0;
}
