#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int fw[N], a[N], b[N];

void upd(int x){
	for(;x<N;x+=x&-x) fw[x] ++;
}

int qry(int x) {
	int s = 0;
	for(;x;x-=x&-x) s += fw[x];
	return s;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x; a[x] = i;
	}
	for(int i=1; i<=n; ++i) cin >> b[i];

	long long res = 0;
	for(int i=n; i>=1; --i) {
		res += qry(a[i]) - qry(max(1, a[i] - b[a[i]]) - 1);
		upd(a[i]);
	}
	memset(fw, 0, sizeof fw);
	for(int i=1; i<=n; ++i) {
		res += qry(min(n, a[i] + b[a[i]])) - qry(a[i]);
		upd(a[i]);
	}

	cout << res;

	return 0;
}