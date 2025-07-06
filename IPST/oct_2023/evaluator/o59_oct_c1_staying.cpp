#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1003, mod = 1e9 + 7;
ll dp[N][3][4];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, ka, kb, kc; cin >> n >> ka >> kb >> kc;

	int a = 0, b = 1, c = 2;
	
	for(int i=1; i<=ka; ++i) dp[i][0][0] = 1;
	
	for(int i=1; i<=n; ++i) {
		for(int vis=0; vis<4; ++vis) {
			for(int j=1; j<=ka and i+j<=n; ++j) {
				dp[i+j][a][vis] += dp[i][c][vis];
				dp[i+j][a][vis] %= mod;
			}

			for(int j=1; j<=kb and i+j<=n; ++j) {
				dp[i+j][b][vis | 1] += dp[i][a][vis];
				dp[i+j][b][vis | 1] %= mod;
			}

			for(int j=1; j<=kc and i+j<=n; ++j) {
				dp[i+j][c][vis | 2] += dp[i][a][vis] + dp[i][b][vis];
				dp[i+j][c][vis | 2] %= mod;
			}
		}
	}

	cout << (dp[n][a][3] + dp[n][b][3] + dp[n][c][3]) % mod;

	return 0;
}