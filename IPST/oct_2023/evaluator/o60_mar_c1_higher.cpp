#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
const int N = 1e6 + 3;
int seg[4*N], L, R, h, idx, n, q;

int qry(int l=1, int r=n, int i = 1) {
	if(L <= l and r <= R) return seg[i];
	if(r < L || l > R) return 0;

	int md = l + (r-l)/2;
	return max(qry(l, md, 2*i), qry(md+1, r, 2*i+1));
}

void upd(int l=1, int r=n, int i=1) {
	if(l == r) { 
		seg[i] = h; return ;
	}
	int md = l + (r-l)/2;
	if(idx <= md) upd(l, md, 2*i);
	else upd(md+1, r, 2*i+1);
	seg[i] = max(seg[2*i], seg[2*i+1]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	while(q--) {
		cin >> idx >> h; idx ++;
		upd();
		int l = 0, r = n, res = 0;
		while(l <= r) {
			int md = l + (r-l)/2;
			L = max(1, idx-md), R = min(n, idx+md);

			if(qry() <= h) {
				res = md;
				l = md + 1;
			}else r = md - 1;
		}

		cout << res << '\n';
	}

	return 0;
}