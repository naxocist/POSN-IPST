#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e3 + 3, mod = 9901;
int a[N], b[N], dp[N][N];
bool no[N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
        for(int j=a[i-1]+1; j<=a[i]; ++j) {
            b[j] = i;
        }
    }
    for(int i=1; i<=m; ++i) {
        int x; cin >> x; no[x] = 1;
    }

    dp[0][0] = 1;
    for(int i=1; i<=a[n]; ++i) {
        for(int j=1; j<=n; ++j) {
            if(no[i] and b[i]!=j) continue ;
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[a[n]][n];
    return 0;
}
// 1 1 1 2 3 3
