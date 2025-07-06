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

void runcase() {
    int n; cin >> n;

    vector<ll> v(n);
    for(auto &x : v) cin >> x;

    for(ll i=2; i<1LL<<57; i<<=1) {
        set<ll> t;
        for(auto x : v) {
            t.insert(x%i);
        }

        if(t.size() == 2) {
            cout << i << ln;
            return ;
        }
    }

    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    cin >> TC; 
    while(TC--) runcase();
    return 0;
}