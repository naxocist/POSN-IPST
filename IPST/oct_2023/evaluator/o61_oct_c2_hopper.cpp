#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k; cin >> n >> k;

	vector<pi> v(n);
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		v[i] = pi(x, i);
	}
	sort(v.begin(), v.end());
	int l = 1, r = 3000, res = 0;
	while(l <= r) {
		int md = l + (r-l)/2, c = 0;
		vector<int> dp(n, 0);
		for(int i=0; i<n; ++i) {
			for(int j=0; j<i; ++j) {
				int a, ai, b, bi; tie(a, ai) = v[i], tie(b, bi) = v[j];
				if(b < a and (ai-bi+n)%n <= md) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			c = max(c, dp[i]);
		}

		if(c >= k) res = md, r = md - 1;
		else l = md + 1;
	}
	cout << res;
	return 0;
}