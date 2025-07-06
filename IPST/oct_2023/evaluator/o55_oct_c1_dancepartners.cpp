#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int N = 1e6+3;
int a, b, h, k;

struct segtree {
	int tree[N];
	void upd(int l, int r, int i, int v, int idx) {
		if(idx<l || idx>r) return ;
		if(l == r) {
			tree[i] = v; 
			return ;
		}
		int md = l+(r-l)/2;
		upd(l, md, 2*i, v, idx); 
		upd(md+1, r, 2*i+1, v, idx);
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}

	int qry(int l, int r, int i, int L, int R) {
		if(R < l || r < L || L > R) return -2e9;
		if(L <= l && r <= R) return tree[i];
		int md = l+(r-l)/2;
		return max(qry(l, md, 2*i, L, R), qry(md+1, r, 2*i+1, L, R));
	}
} b1, b2;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	vector<pi> A;
	vector<int> K;
	for(int i=0; i<n; ++i) {
		cin >> h >> a;
		A.emplace_back(h, a);
	}

	for(int i=0; i<n; ++i) {
		cin >> k >> b;
		K.emplace_back(k);
		b1.upd(1, n, 1, b-k, i+1);
		b2.upd(1, n, 1, b+k, i+1);
	}

	for(int i=0; i<n; ++i) {
		tie(h, a) = A[i];
		int t = lower_bound(K.begin(), K.end(), h) - K.begin() + 1;
		cout << max(a+h+b1.qry(1, n, 1, t, n), a-h+b2.qry(1, n, 1, 1, t-1)) << '\n';
	}
	return 0;
}
