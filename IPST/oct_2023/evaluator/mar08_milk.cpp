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
int pa[N];

int par(int u) {
	return (pa[u] == u ? u : pa[u] = par(pa[u]));
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	iota(pa, pa+n, 0);
	while(q--) {
		char c; int x, y; cin >> c >> x >> y;
		if(c == 'c') pa[par(x)] = par(y);
		else cout << (par(x) == par(y) ? "yes" : "no") << '\n';
	}    
    return 0;
}
