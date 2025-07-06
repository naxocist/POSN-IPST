#include "triplets.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
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
const ll N = 1e5 + 3, mod = 9377;
vector<int> adj[N], rev[N];

stack<int> st, t;
bool vis[N];

void dfs(int u) {
    if(vis[u]) return ;
    vis[u]=1;
    for(auto v : adj[u]) {
        dfs(v);
    }
    st.emplace(u);
}

void dfs2(int u) {
    if(vis[u]) return ;
    vis[u]=1;
    t.emplace(u);
    for(auto v : rev[u]) {
        dfs2(v);
    }
}

int cal(int n){
    n%=mod;
    return n*(n-1)%mod*(n-2)%mod;
}

int count_triplets(int n, std::vector<int> U, std::vector<int> V, std::vector<int> col){
    for(int i=0; i<U.size();++i){
        adj[U[i]].pb(V[i]);
        rev[V[i]].pb(U[i]);
    }

    for(int i=0; i<n; ++i) dfs(i);
    int ret = cal(n);
    for(int i=0; i<N;++i)vis[i]=0;
    while(st.size()) {
        int u = st.top(); st.pop();
        if(vis[u])continue;
        dfs2(u);
        int sz = t.size();
        map<ll, ll> cnt;
        while(t.size()) {
            int x=t.top();t.pop();
            cnt[col[x]] ++;
        }
        for(auto e : cnt) {
            ll c, d; tie(c, d) = e;
            ret -= cal(d);
            ret=(ret+mod)%mod;
        }
    }

  return ret;
}   
