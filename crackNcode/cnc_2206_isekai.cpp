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
const ll INF = 2e9, mod = 1e9 + 7, P = 31;

ll add(ll a, ll b) { return (a + b)%mod; }
ll sub(ll a, ll b) { return (a - b + mod)%mod; }
ll mul(ll a, ll b) { return (a * b)%mod; }
int ch(char c) { return c - 'A' + 1; }

void runcase() {
    int n, q; cin >> n >> q;
    vector<ll> pref(n+1), suff(n+2), pw(n+1);
    string s; cin >> s; s = '.' + s;

    pw[0] = 1;
    for(int i=1; i<=n; ++i) pw[i] = mul(pw[i-1], P);

    for(int i=1; i<=n; ++i) {
        pref[i] = add(pref[i-1], mul(ch(s[i]), pw[i-1]));
    }

    for(int i=n; i>=1; --i) {
        suff[i] = add(suff[i+1], mul(ch(s[i]), pw[n-i]));
    }

    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        ll ab = mul(sub(pref[b], pref[a-1]), pw[n-b]);
        ll cd = mul(sub(pref[d], pref[c-1]), pw[n-d]);
        ll abcd = add(ab, cd);

        ll dc = mul(sub(suff[c], suff[d+1]), pw[c]); 
        ll ba = mul(sub(suff[a], suff[b+1]), pw[a]);
        ll dcba = add(dc, ba);

        dbg(abcd, dcba);

        cout << (abcd == dcba ? "YES" : "NO") << ln;
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