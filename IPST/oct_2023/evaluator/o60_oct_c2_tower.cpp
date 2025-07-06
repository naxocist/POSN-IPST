#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;

struct node {
	int mx, cnt, mxl, mxr;
} seg[4*N];

int lz[4*N];

node un(node l, node r) {
	node res;
	res.mx = max(l.mx, r.mx);
	res.cnt = l.cnt*(res.mx==l.mx) + r.cnt*(res.mx==r.mx) - (l.mxr&&r.mxl)*(l.mx==r.mx);
	res.mxl = l.mxl && (res.mx == l.mx);
	res.mxr = r.mxr && (res.mx == r.mx);
	return res;
}

void pushlz(int i, int l, int r) {
	if(!lz[i]) return ;
	seg[i].mx += lz[i];
	if(l != r) lz[2*i] += lz[i], lz[2*i+1] += lz[i];
	lz[i] = 0;
}

void build(int i, int l, int r) {
	if(l == r) {
		seg[i] = {0, 1, 1, 1}; 
		return ;
	}
	int md = l+(r-l)/2;
	build(2*i, l, md); build(2*i+1, md+1, r);
	seg[i] = un(seg[2*i], seg[2*i+1]);
	return ;
}

void upd(int i, int l, int r, int x, int y, int v) {
	pushlz(i, l, r);
	if(r < x || l > y) return ;
	if(x <= l && r <= y) {
		lz[i] += v;
		pushlz(i, l, r);
		return ;
	} 
	int md = l+(r-l)/2;
	upd(2*i, l, md, x, y, v); upd(2*i+1, md+1, r, x, y, v);
	seg[i] = un(seg[2*i], seg[2*i+1]);
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	build(1, 1, n);
	while(q--) {
		int l, r, x; cin >> l >> r >> x;
		upd(1, 1, n, l, r, x);
		cout << seg[1].mx << ' ' << seg[1].cnt << '\n';
	}
	return 0;
} 