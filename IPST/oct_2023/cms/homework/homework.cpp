#include "homework.h"
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
using T = tuple<ll, ll, ll>;
const int N = 1e5 + 3;
vector<int> adj[N];
bitset<N> vis;
ll earliest[N];

ll nxt(ll s, ll m){
    return s+((m-(s%m))%m);
}

int homework(int n, vector<vector<int>> hw, vector<vector<int>> B) {

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i=0; i<n; ++i) {
        for(int x : B[i]) adj[x].pb(i);
        earliest[i] = nxt(hw[i][0],hw[i][2]);
        if(hw[i][3] == 0) {
            if(earliest[i]<=hw[i][1])
                pq.emplace(earliest[i], i);
        }
    }
    vis.reset();
    int res = 0;
    while(pq.size()) {
        ll t, u; tie(t, u) = pq.top(); pq.pop();
        if (vis[u])continue;
        // cout << u << " " << t << endl;
        res++;
        vis[u]=1;
        for (auto v : adj[u]) {
            // printf("-- %d %d\n",v,u);
            --hw[v][3];
        }
        for(auto v : adj[u]) {
            if(hw[v][3] > 0) continue ;
            ll t2 = earliest[v];
            ll t1 = nxt(t+1, hw[v][2]);
            // if(t1 > t2) swap(t1, t2);
            if(t1 < t2 and t2 >= hw[v][0] and t2 <= hw[v][1]) {
                pq.emplace(t2, v);
            }else if(t1 >= hw[v][0] and t1 <= hw[v][1]){
                pq.emplace(t1, v);
            }
        }
    }
    return res;
}