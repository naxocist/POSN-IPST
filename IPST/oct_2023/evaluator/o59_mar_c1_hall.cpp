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
const ll N = 1e4 + 3, mod = 1e9 + 7, p = 998244353; 
ll ar[2*N];
int n;

void norm(ll &x) {
    x %= mod, x += mod, x %= mod;
    return ;
}

bool f(int x) {
    x ++;
    ll hash = 0, t = 1;
    for(int i=1; i<=x; ++i) {
        hash = hash*p + ar[i], norm(hash);
        if(i>1) t *= p, norm(t);
    }

    set<ll> seen;
    seen.insert(hash);
    for(int i=1; i<=n-1; ++i) {
        hash -= t*ar[i]; norm(hash);
        hash *= p; norm(hash);
        hash += ar[i+x]; norm(hash);

        if(seen.find(hash) != seen.end()) {
            return false;
        }else {
            seen.insert(hash);
        }
    }

    return true;
}

void runcase() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> ar[i], ar[i+n] = ar[i];

    int l = 0, r = n-1, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        if(f(md)) r = md - 1, res = md;
        else l = md + 1;
    }

    cout << res;
    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}
