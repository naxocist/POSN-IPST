#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
using ll = long long;
ll qs[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b; cin >> n >> a >> b;
	for(int i=1; i<=n; ++i) cin >> qs[i], qs[i]+=qs[i-1];

	ll res = -LLONG_MAX;
	multiset<ll> ms;
	for(int i=a; i<=n; ++i) {
		if(i > b) ms.erase(ms.find(qs[i-b-1]));
		ms.insert(qs[i-a]);
		res = max(res, qs[i] - *ms.begin());
	}
	cout << res;
	return 0;
}