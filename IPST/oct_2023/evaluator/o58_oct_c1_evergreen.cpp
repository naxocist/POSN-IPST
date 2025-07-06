#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3;
vector<ll> v;

ll cal(ll n) {
	if(n&1) return (n+1)*(n+1)/4;
	return (n+2)*n/4;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, k; cin >> n >> k;
	v.resize(n);
	
	for(auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	ll l = 0, r = 1e9, res = 0;
	while(l <= r) {
		ll md = l + (r-l)/2;
		ll t = 0;
		for(int i=0; i<n; ++i) {
			t += (md+1)*(md+1);
			ll over = 0;
			if(i > 0) over = (v[i-1]+md)-(v[i]-md)+1;
			if(over <= 0) continue ;
			t -= cal(over);
		}
		if(t >= k) r = md - 1, res = md;
		else l = md + 1;
	}

	cout << res;
	return 0;
}