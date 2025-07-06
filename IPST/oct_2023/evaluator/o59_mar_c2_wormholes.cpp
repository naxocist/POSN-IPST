#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 100;
vector<pi> p;
int dp[N][N];

int dist(pi a, pi b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k, m; cin >> k >> m;
    int mk = 2*k;
    for(int i=0; i<mk; ++i) {
        for(int j=0; j<mk; ++j) dp[i][j] = INF;
        dp[i][i] = 0;
    }
    
    for(int i=0; i<k; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int u = 2*i, v = 2*i+1;
        p.pb(a, b); p.pb(c, d);
        dp[u][v] = dp[v][u] = 0;
    }
    for(int i=0; i<mk; ++i) {
        for(int j=0; j<mk; ++j) {
            dp[i][j] = min(dp[i][j], dist(p[i], p[j]));
        }
    }

    for(int k=0; k<mk; ++k){
        for(int i=0; i<mk; ++i) {
            for(int j=0; j<mk; ++j) {
                if(dp[i][k] == INF || dp[k][j] == INF) continue ;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }


    while(m--) {
        int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
        int res = dist(pi(sx, sy), pi(tx, ty));
        for(int i=0; i<mk; ++i) {
            for(int j=0; j<mk; ++j) {
                if(dp[i][j] == INF) continue ;

                res = min(res, dist(pi(sx, sy), p[i]) + dp[i][j] + dist(pi(tx, ty), p[j]));
            }
        }
        cout << res << '\n';
    }
    return 0;
}
