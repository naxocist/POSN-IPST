#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
double qs[N];
int main() {
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; ++i) cin >> qs[i], qs[i] += qs[i-1];

	while(q--) {
		double a, b, u; cin >> a >> b >> u;
		double avg = (qs[b] - qs[a-1]) / (b-a+1);

		int l = 0, r = n, res = -1;
		while(l <= r) {
			int md = l + (r-l)/2;

			double k = new_avg;

			if(k >= u) r = md - 1, res = md;
			else l = md + 1;
		}

		cout << res << '\n';
	}
	

	return 0;
}