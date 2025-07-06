#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int dp[2][N*10], h[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, s, res = 0; cin >> n >> s;
	for(int i=1; i<=n; ++i) {
		int H; cin >> H;
		for(int j=1; j<=H; ++j) cin >> h[j], h[j] += h[j-1];

		for(int j=0; j<=s-i+1; ++j) {
			for(int k=0; k<=H and j-k >= 0; ++k) {
				dp[i&1][j] = max(dp[i&1][j], dp[i&1^1][j-k] + h[k]);
			}
			res = max(res, dp[i&1][j]);
		}
	}
	cout << res;
	return 0;
}