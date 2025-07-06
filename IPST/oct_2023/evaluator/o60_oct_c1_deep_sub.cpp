#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int l[N], r[N], cnt[N];
int s, a, b, L;
int dir() {
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}

int dfs(int u) {
	if(u) L--;
	if(!L) return u;
	int c = (l[u] > 0) + (r[u] > 0);
	if(c == 2) return dfs((dir() == 0 ? l[u] : r[u]));
	else if(!c) return u;

	if(l[u] > 0) return dfs(l[u]);
	return dfs(r[u]);
}

int main() {
	int n, q; cin >> n >> q;
	for(int i=0; i<n; ++i) {
		cin >> l[i] >> r[i];
	}

	while(q--) {
		cin >> L >> s >> a >> b;
		cout << dfs(0) << '\n';
	}
	return 0;
}