#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
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
const int N = 203;
int dp[N][N][33];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while(1) {
        int n; cin >> n;
        if(n == 0) break ;

        vector<char> v(n);
        vector<int> idx(30);
        vector<vector<pi>> can(n, vector<pi>(n));

        for(int i=0; i<n; ++i) {
            char c; cin >> c;
            idx[c-'a'] = i;
            v[i] = c;
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                int d; char c; 
                scanf("%d- %c", &d, &c);
                can[i][j] = pi(d, idx[c-'a']);
            }
        }

        int t; cin >> t;
        while(t--) {
            string s; cin >> s;
            int m = s.size();
            for(int i=0; i<m; ++i) 
                for(int j=0; j<m; ++j) 
                    for(int k=0; k<n; ++k) 
                        dp[i][j][k] = INF;
            for(int i=0; i<m; ++i) 
                dp[i][i][idx[s[i]-'a']] = 0;

            for(int sz=2; sz<=m; ++sz) {
                for(int l=0; l<m; ++l) {
                    int r = l + sz - 1;
                    if(r >= m) continue ;
                    for(int k=l; k<r; ++k) {
                        for(int i=0; i<n; ++i) {
                            for(int j=0; j<n; ++j) {
                                dp[l][r][can[i][j].second] = min(dp[l][r][can[i][j].second], dp[l][k][i] + dp[k+1][r][j] + can[i][j].first);
                            }
                        }
                    }
                }
            }

            pi res = pi(INF, INF);
            for(int i=0; i<n; ++i) {
                if(dp[0][m-1][i] < res.first) {
                    res = pi(dp[0][m-1][i], i);
                }else if(dp[0][m-1][i] == res.first) 
                    res.second = min(res.second, i);
            }
            cout << res.first << '-' << v[res.second] << '\n';
        }
        cout << '\n';
    }
    return 0;   
}
