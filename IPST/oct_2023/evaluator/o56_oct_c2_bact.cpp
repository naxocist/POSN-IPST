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
int n, m, k;
int ar[33][33];
int dp[33][33][33][33];
bool vis[33][33][33][33];
unordered_map<int, int> cnt, t;

int f(int r1, int r2, int c1, int c2) {
    if(vis[r1][r2][c1][c2]) return dp[r1][r2][c1][c2];
    vis[r1][r2][c1][c2] = 1;

    int res = 0;
    if(r1 == r2) 
    {
        t.clear();
        for(int i=c1; i<=c2; ++i) t[ar[r1][i]] ++;
        for(auto e : t) if(e.second == cnt[e.first]) res ++;
    }
    else if(c1 == c2) 
    {
        t.clear();
        for(int i=r1; i<=r2; ++i) t[ar[i][c1]] ++;
        for(auto e : t) if(e.second == cnt[e.first]) res ++;
    }
    else {
        res = max(res, f(r1+1, r2, c1, c2) + f(r1, r1, c1, c2));
        res = max(res, f(r1, r2-1, c1, c2) + f(r2, r2, c1, c2));
        res = max(res, f(r1, r2, c1+1, c2) + f(r1, r2, c1, c1));
        res = max(res, f(r1, r2, c1, c2-1) + f(r1, r2, c2, c2));
    }
    return dp[r1][r2][c1][c2] = res;
    
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=m; ++j) {
            cin >> ar[i][j], cnt[ar[i][j]] ++;
        }
    cout << f(1, n, 1, m);
    return 0;
}
