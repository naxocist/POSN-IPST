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
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include "switches.h"
const int N = 5e4 + 3;
vector<pi> adj[N];
bool vis[N][21];

long long minimum_energy(int n, int m, int k, std::vector<int> f, std::vector<int> L, 
                         std::vector<int> R, std::vector<int> C){
    vector<ll> val(n+1);
    for(int i=1; i<=n; ++i) val[i] = f[i-1];
    for(int i=1; i<=n; ++i) {
        adj[i].pb(i-1, val[i]); adj[i-1].pb(i, val[i]);
    }

    for(int i=0; i<m; ++i) {
        int u=L[i],v=R[i],w=C[i]; u++, v++;
        // cout <<u<<' '<<v<<' '<<w<<endl;
        adj[u-1].pb(v,w);adj[v].pb(u-1,w);
    }

    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 0, k);
    vector<vector<ll>> dist(n+3,vector<ll>(k+1, LLONG_MAX));
    dist[0][k]=0;
    ll ret=LLONG_MAX;
    while(pq.size()) {
        int u, k; ll d; tie(d, u, k)=pq.top();pq.pop();
        cout << u << ' ' << d << '\n';
        if(u==n)ret=min(ret,dist[u][k]);
        for(auto e :adj[u]) {
            int v;ll vw; tie(v,vw)=e;
            int l=u,r=v; if(l>r)swap(l,r);  
            ll use = abs(val[l+1]*val[l+1] - val[r]*val[r]);
            if(l!=n and use<vw and k>0 and use+dist[u][k]<dist[v][k-1]){
                dist[v][k-1]=use+dist[u][k];
                pq.emplace(dist[v][k-1],v,k-1);
            }else if(dist[u][k]+vw<dist[v][k]){
                dist[v][k]=dist[u][k]+vw;
                pq.emplace(dist[v][k],v, k);
            }
        }
        // if(k==0) continue ;
        // cout << u << endl;
        // for(int i=0; i<=n; ++i) {
        //     if(i==u)continue;
        //     int l=i,r=u;
        //     if(l>r)swap(l,r);
        //     if(l==n)continue;
        //     // cout<<l<<' '<<r<<' '<<dist[i][k-1]<<endl;
        //     ll w = abs(v[l+1]*v[l+1] - v[r]*v[r]);
        //     if(d+w<dist[i][k-1]){
        //         dist[i][k-1]=d+w;
        //         pq.emplace(d+w, i, k-1);
        //     }
        // }
        // div()
    }
    // for(int i=0;i<=k;++i)ret=min(ret,dist[n][i]);
	return ret;
}
