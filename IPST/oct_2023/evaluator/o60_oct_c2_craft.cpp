#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
using ll = long long;
using pi = pair<ll, ll>;
const int N = 23;
ll c[N];

ll f(ll n, ll w) {
	if(n == 1) return max(0LL, w);
	
	ll x = w*2;
	x -= c[n-1];
	ll mx = -INF;
	if(x&1^1) mx = 2*f(n-1, x/2);
	else mx = f(n-1, x/2) + f(n-1, x/2+1);

	x = w*2 + 1;
	x -= c[n-1];
	ll mx2 = -INF;
	if(x&1^1) mx2 = 2*f(n-1, x/2);
	else mx2 = f(n-1, x/2) + f(n-1, x/2+1);

	return max(mx, mx2);
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, k; cin >> n >> k;
	for(int i=1; i<n; ++i) cin >> c[i];

	ll res = f(n, k);
	if(res <= 0) {
		cout << -1; return 0;
	}
	cout << res;
	return 0;
}