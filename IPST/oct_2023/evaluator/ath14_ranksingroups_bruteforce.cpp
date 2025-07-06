#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
unordered_map<int, vector<int>> um;
const int N = 1e5 + 3;
int g[N];

void solve() {
    int n, q; cin >> n >> q;
    um.clear();
    for(int i=1; i<=n; ++i) g[i] = i, um[i].pb(i);

    while(q--) {
        int t, x, y; cin >> t;
        if(t == 1) {
            cin >> x >> y; 
            for(int s : um[g[x]]) {
                vector<int> &v = um[g[y]];

                int u = upper_bound(v.begin(), v.end(), s) - v.begin();
                // cout << "T : "<<t << ' ';
                v.insert(v.begin()+u, s);
                g[s] = g[y];
            }
        }else {
            cin >> x;
            vector<int> &v = um[g[x]];
            int t = upper_bound(v.begin(), v.end(), x) - v.begin();
            cout <<v.size()-t+1 << '\n';
        }

    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
