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
using T = tuple<double, int, int, int>;
const int N = 1003;
int dsu[N];

int par(int u) {
	return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
	u = par(u), v = par(v);
	if(u == v) return ;
	dsu[u] = v;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<T> edge;
	for(int i=0; i<m; ++i){
		int u, v; double w;
		cin >> u >> v >> w;
		// cout << u << ' ' << v << ' ' << w << endl;
		edge.pb(w, u, v, i);
	}

	iota(dsu, dsu+N, 0);
	double a;
	vector<int> b;
	sort(all(edge));

	for(auto e : edge) {
		double w; int u, v, i; tie(w, u, v, i) = e;
		if(par(u) == par(v)) continue ;
		un(u, v);
		a += w;
		b.emplace_back(i);
	}
	sort(all(b));
	cout << a << '\n';
	for(auto x : b) cout << x << '\n';
	return 0;
}