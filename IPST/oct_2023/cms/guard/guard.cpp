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
const ll mod = 1e9 + 7;
const ll N = 1e5 + 3, M = 1e6 + 3;
vector<int> v, res, adj[N];
ll prime[M];
ll n;
unordered_map<ll, ll> cnt;

void dfs(int u) {
    for(auto v : adj[u]) dfs(v);

    // div()
    // show(v[u])
    int x = v[u];
    while(x != 1)   {
        cnt[prime[x]] ++;
        // cout << prime[x] << endl;
        x /= prime[x];
    }

    ll r = 1;
    for(auto e : cnt) {
        r *= e.second + 1;
        r %= mod;
    }

    res[u] = r;
    return ;
}

vector<int> guard(int N, vector<int> A, vector<int> p) {
    n = N;
    v = A;
    res.resize(n);
    prime[2] = 2;
    for(int i=2; i<M; ++i) prime[i] = i;
    for(ll i=2; i<M; ++i) {
        if(prime[i] != i) continue ;
        for(ll j=i*i; j<M; j+=i) {
            prime[j] = i;
        }
    }

    for(int i=0; i<n; ++i) {
        if(i>0)adj[p[i]].pb(i);
        // cout << p[i] << ' ';
    }
    // cout << endl;
    dfs(0);
    
    return res;
}