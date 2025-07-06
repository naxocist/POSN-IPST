#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 3;
int dsu[N], G;
int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
	G--;
}

int main() {
	int k, m; cin >> k >> m;
	G = (1<<k) + 1;
	iota(dsu, dsu+N, 0);

	for(int i=1; i<=m; ++i){
		int a, b; cin >> a >> b;
		un(b, b+(1<<a));
		if(G == 1) {
			cout << i; break ;
		}
	}
	return 0;
}