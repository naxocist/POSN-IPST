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
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;
const int N = 1e5 + 3;
bitset<N> vis;

void runcase() {
    vis.reset();
    int n; cin >> n;
    vector<int> v(n); for(auto &x : v) cin >> x, x--;

    int mx = 0;
    for(int i=0; i<n; ++i) {
        if(vis[i]) continue ;

        int c = i, l = 0;
        while(!vis[c]) {
            l ++;
            vis[c] = 1;
            c = v[c];
        }

        if(l > 1) l = l%2 ? 3 : 2; 
        mx = max(mx, l);
    }

    cout << mx << ln;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    cin >> TC; 
    while(TC--) runcase();
    return 0;
}