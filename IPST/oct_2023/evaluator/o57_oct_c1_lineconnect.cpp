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
    int n; cin >> n;
    iota(dsu, dsu+n, 0);
    vector<int> v(n+1);
    for(int i=1; i<=n; ++i) cin >> v[i];

    for(int i=0; i<n-2; ++i) {
        int u, v; cin >> u >> v;
        un(u, v);
    }    

    vector<int> pa;
    for(int i=1; i<=n; ++i) if(i == par(i)) pa.pb(i);

    vector<int> a, b;
    int t = 0;
    for(auto p : pa) {
        for(int i=1; i<=n; ++i) {
            if(par(i) == p) {
                t&1 ? a.pb(v[i]) : b.pb(v[i]);
            }
        }
        t++;
    }
    sort(all(a)), sort(all(b));

    int mx = 2e9;
    // for(auto x : a) cout << x << ' '; cout << endl;
    // for(auto x : b) cout << x << ' '; cout << endl;
    for(auto x : a) {
        int i = upper_bound(all(b), x) - b.begin();
        if(i < b.size()) mx = min(mx, abs(x - b[i]));
        if(i > 0) mx = min(mx, abs(x - b[i-1]));
    }

    cout << mx;
    return 0;
}
