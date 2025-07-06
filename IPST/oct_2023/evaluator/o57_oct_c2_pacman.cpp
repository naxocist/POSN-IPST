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
const int N = 1006;
ll dp[N][N][3], ar[N][N];

void mx(ll &a, ll b) {
    a = max(a, b);
    return ;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin >> ar[i][j];
            dp[i][j][2] = max(dp[i][j-1][1] + ar[i][j], dp[i-1][j][1] + ar[i][j]);
            dp[i][j][1] = max(dp[i][j-1][0] + ar[i][j], dp[i-1][j][0] + ar[i][j]);
            for(int k=0; k<=2; ++k) {
                dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][k], dp[i][j-1][k]});
            }
            // cout << i << ' ' << j << endl;
            // for(int k=0; k<=2; ++k) cout << dp[i][j][k] << '\n';
            // div()
        }
    }

    cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    return 0;
}
