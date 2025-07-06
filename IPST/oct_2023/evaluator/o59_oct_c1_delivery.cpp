#include <bits/stdc++.h>
using namespace std;
#define INF 1e6
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 17;
unordered_map<int, int> idx;
int dp[N][N], in[N], out[N];
int k, l, q;

int f(int a, int b) {
    int aa = a < 1<<k;
    int bb = b < 1<<k;
    if(aa^bb) return INF;
    if (!aa)a -= 1 << k;
    if (!bb)b -= 1 << k;
    int cnt = 0;
    for(;a!=b;cnt++) {
        if(a > b) a/=2;
        else if(a < b) b/=2;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> k >> l >> q;
    vector<int> s, t;
    for(int i=0; i<l; ++i){
        int x, y; cin >> x >> y;
        t.pb(x), t.pb(y);
        in[i] = x, out[i] = y;
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    int m = 0;
    for(auto x : t) {
        idx[x] = m ++;
    }

    for(auto x : t) {
        for(auto y : t) {
            int a = idx[x], b = idx[y];
            dp[a][b] = f(x, y);
        }
    }

    for(int i=0; i<l; ++i) {
        int a = idx[in[i]], b = idx[out[i]];
        dp[a][b] = dp[b][a] = 1;
    }

    for(int k=0; k<m; ++k) {
        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                if(dp[i][k] == INF || dp[k][j] == INF) continue ;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q--) {
        int a, b; cin >> a >> b;
        int res = f(a, b);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                res = min(res, f(a, t[i]) + dp[i][j] + f(t[j], b));
            }
        }
        cout << res << '\n';
    }

    return 0;
}
 