#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e5 + 3;
int ar[N];
int seg[4*N], lz[4*N];
pi q[N];

void pushlz(int i, int l, int r) {
	if(!lz[i]) return ;
	seg[i] = lz[i];
	if(l != r) {
		lz[2*i] = lz[i];
		lz[2*i+1] = lz[i];
	}
	lz[i] = 0;
}

void upd(int i, int l, int r, int x, int y, int v) {
	pushlz(i, l, r);
	if(r < x or l > y) return ;
	if(x <= l and r <= y) {
		lz[i] = v;
		pushlz(i, l, r);
		return ;
	}
	int md = l+(r-l)/2;
	upd(2*i, l, md, x, y, v), upd(2*i+1, md+1, r, x, y, v);
}

int qry(int i, int l, int r, int x) {
	pushlz(i, l, r);
	if(l == r) return seg[i];
	int md = l + (r-l)/2;
	if(x <= md) return qry(2*i, l, md, x);

	return qry(2*i+1, md+1, r,x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; ++i) {
    	cin >> ar[i];
    }

    for(int i=1; i<=m; ++i) cin >> q[i].first, q[i].second = i;
    sort(q+1, q+1+m);
    vector<int> dff(m+1);
	upd(1, 1, n, 1, n, ar[1]);

   	for(int i=2; i<=n; ++i) {
   		int l = 1, r = m, res = 0;
   		while(l <= r) {
   			int md = l + (r-l)/2;
   			if(qry(1, 1, n, md) + q[md].first >= ar[i]) res = md, r = md - 1;
   			else l = md + 1;
   		}
   		dff[1] ++, dff[res] --;
   		upd(1, 1, n, res, m, ar[i]);
   	}

   	for(int i=1; i<=m; ++i) dff[i] += dff[i-1];

   	vector<int> res(m+1);
   	for(int i=1; i<=m; ++i) res[q[i].second] = dff[i];

   	for(int i=1; i<=m; ++i) cout << res[i] << '\n';
    return 0;
}
