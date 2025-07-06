#include <bits/stdc++.h>
using namespace std;
using T = tuple<double, int, int>;
using pi = pair<int, int>;
const int N = 1003;
vector<T> adj[N];
bool vis[N];


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i=0; i<m; ++i){
		int u, v; double w;
		cin >> u >> v >> w;
		adj[u].emplace_back(w, v, i); adj[v].emplace_back(w, u, i);
	}

	priority_queue<T, vector<T>,greater<T>> pq;
	pq.emplace(0.0, 0, -1);

	vector<int> a;
	double b = 0;
	while(pq.size()) {
		double d; int u, t;
		tie(d, u, t) = pq.top(); pq.pop();

		if(vis[u]) continue ;
		vis[u] = 1;
		if(t!=-1) a.emplace_back(t);
		b+=d;
		for(auto e : adj[u]) {
			double w; int v, x;
			tie(w, v, x) = e;
			pq.emplace(w, v, x);
		}
	}
	sort(a.begin(), a.end());
	cout << fixed;
	cout << b << '\n';
	for(auto x : a) cout << x << '\n';
	return 0;
}