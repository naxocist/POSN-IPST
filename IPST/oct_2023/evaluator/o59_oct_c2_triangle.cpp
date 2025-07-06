#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 103, mod = 1e9 + 7;
ll dp[N][N];
int n, k;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            ll &x = dp[i][j];
            x = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + min(k, i-1) + min(k, j-1);
            x %= mod;
            for(int m=1; m<=min(k, i-1); ++m)
                x += dp[i-m-1][j-1], x %= mod;
            for(int m=1; m<=min(k, j-1); ++m)
                x += dp[i-1][j-m-1], x %= mod;      
            
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    cout << dp[n][n];
    return 0;
}
