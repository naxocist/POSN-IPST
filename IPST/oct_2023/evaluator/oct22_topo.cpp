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
vector<int> adj[N];
int in[N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    while(m--) {
    	int u, v; cin >> u >> v;
    	adj[u].pb(v);
    	in[v] ++;
    }

    queue<int> q;
    for(int i=1; i<=n; ++i) 
    	if(in[i] == 0) q.emplace(i);

    vector<int> res;
   	while(q.size()) {
   		int u = q.front(); q.pop();
   		res.pb(u);
   		for(auto v : adj[u]) {
   			if(--in[v] == 0) q.emplace(v);
   		}
   	}

   	if(res.size() < n) cout << "no";
   	else for(auto x : res) cout << x << '\n'; 
    return 0;
}
