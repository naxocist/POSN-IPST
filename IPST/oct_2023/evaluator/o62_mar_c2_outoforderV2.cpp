#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;
const int N = 1e5 + 3;
vector<int> seg[4*N], v, d;
int L, R, V, n;

void build(int i, int l, int r) {
	if(l == r) {
		seg[i].push_back(v[l]);
		return ;
	}

	int md = l + (r-l)/2;
	build(2*i, l, md); build(2*i+1, md+1, r);
	merge(all(seg[2*i]), all(seg[2*i+1]), back_inserter(seg[i]));
}
 
int qry(int i, int l, int r, int m) {
	if(r < L || l > R) return 0;
	if(L <= l && r <= R) {
		int t = upper_bound(all(seg[i]), V) - seg[i].begin();
		if(m) return t;
		else return seg[i].size()-t; 
	}

	int md = l + (r-l)/2;
	return qry(2*i, l, md, m) + qry(2*i+1, md+1, r, m);
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	v.resize(n+1), d.resize(n+1);
	for(int i=1; i<=n; ++i) cin >> v[i];
	for(int i=1; i<=n; ++i) cin >> d[i];

	build(1, 1, n);
	ll res = 0;
	for(int i=1; i<=n; ++i) {
		V = v[i];
		L = max(1, i-d[i]), R = i-1;
		if(d[i]) res += qry(1, 1, n, 0);

		L = i+1, R = min(n, i+d[i]);
		if(d[i]) res += qry(1, 1, n, 1);
	}

	cout << res;
	return 0;
}