#include <bits/stdc++.h>
using namespace std;
#include "guard.h"
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
const int N = 1e5 + 3, M = 1e6 + 3;
vector<int> val, res, adj[N];
ll prime[M], inv[M];
ll n, R = 1, t = 0;
int sz[N], st[N], ed[N], ver[3*N], cnt[M];


ll binpow(ll x, ll y) {
    ll res = 1;
    for(;y;y>>=1, x*=x, x%=mod) 
        if(y&1) res=(res*x)%mod;
    return res;
}


void pre(int u) {
    sz[u] = 1;
    ver[++t] = u;
    st[u] = t;
    // t++;
    for(auto v : adj[u]) {
        pre(v);
        sz[u] += sz[v];
    }
    ed[u] = t;
}


void addfactor(int x, int y) {
    while(x != 1)   {
        R *= inv[cnt[prime[x]] + 1], R %= mod;
        cnt[prime[x]] += y;
        R *= cnt[prime[x]] + 1, R %= mod;
        x /= prime[x];
    }
    return ;
}


void dfs(int u, bool keep) {
    int bigCh = -1,  mx = 0;
    for(auto v : adj[u]) {
        if(sz[v] > mx) mx = sz[v], bigCh = v;
    }

    for(auto v : adj[u]) {
        if(v != bigCh) dfs(v, 0);
    }

    if(bigCh != -1) dfs(bigCh, 1);
    // show(u);
    for(auto v : adj[u]) {
        if(v != bigCh) {
            for(int i=st[v]; i<=ed[v]; ++i) {
                // cout << ver[i] <<' ';
                addfactor(val[ver[i]], 1);
            }
        }
    }
    // cout << endl;
    addfactor(val[u], 1);
    res[u] = R;
    if(!keep) {
        for(int i=st[u]; i<=ed[u]; ++i) {
            addfactor(val[ver[i]], -1);
        }
    }
    return ;
}

vector<int> guard(int N, vector<int> A, vector<int> p) {
    n = N;
    val = A;
    res.resize(n);
    iota(prime, prime+M, 0);
    for(ll i=2; i<M; ++i) {
        if(prime[i] != i) continue ;
        for(ll j=i*i; j<M; j+=i) {
            prime[j] = i;
        }
    }

    inv[0] = inv[1] = 1;
    for(int i=2; i<M; ++i) inv[i] = binpow(i, mod-2);
    for(int i=1; i<n; ++i) adj[p[i]].pb(i);
    pre(0);
    dfs(0, 1);
    return res;
}

signed main(int argc, const char **argv) {
    int N;
    assert(scanf("%d", &N));
    std::vector<int> A(N), P(N);
    for(int i = 0; i < N; i++) {
        assert(scanf("%d", &A[i]));
    }
    P[0] = -1;
    for(int i = 1; i < N; i++) {
        assert(scanf("%d", &P[i]));
    }
    std::vector<int> Ans = guard(N, A, P);
    for(int i = 0; i < N; i++) {
        printf("%d ", Ans[i]);
    }
    return 0;
}