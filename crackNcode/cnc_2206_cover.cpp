#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename S, typename T> S amax(S &a, const T &b) { if(b > a) a = b; return a; }
template<typename S, typename T> S amin(S &a, const T &b) { if(b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
#define ln '\n'
using ll = long long;
using pi = pair<int, int>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;
const int N = 1e5 + 3;
vector<int> adj[N];

void bfs(int s, vector<int> &d) {
    fill(all(d), -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(d[v] != -1) continue ;
            q.push(v); d[v] = d[u] + 1;
        }
    }
}


void runcase() {
    int n, m, p, a, b; cin >> n >> m >> p >> a >> b; a--, b--;
    while(m--) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    vector<int> A(n), B(n), res(n); bfs(a, A), bfs(b, B);
    priority_queue<pi> pq;
    for(int i=0; i<n; ++i) pq.emplace(A[i], i);
    for(int i=0; i<n; ++i) {
        // B takes care of the popped elements
        while(pq.size() and B[pq.top().second] <= i) pq.pop();
        if(pq.size()) res[i] = pq.top().first;
    }

    while(p--) {
        int x; cin >> x;
        cout << res[x] << ln;
    }
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}