#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

#include "fatigue.h"
const int N = 1e5 + 3;
vector<int> line;
vector<ll> wall;
unordered_map<int, int>idx;
map<int,vector<int>>xx;
vector<int> ww;

void initialize(int N, std::vector<int> pos, std::vector<int> w){
    ww = w;
    for(int i=0;i<N;++i){
        xx[pos[i]].pb(i);
    }

    for(auto x : xx){
        int id=x.first;
        line.pb(id);
    }
    wall.resize(line.size());
    for(int i=0;i<line.size();++i) {
        //x = poscout
        // cout << x << ' ';
        for(int j : xx[line[i]]) {
            idx[j]=i;
            wall[i]+=(ll)w[j];
        }
        // cout << line[i] << ' ';
    }
    // cout << endl;
    return;
}
void change_weight(int X, int V){
    wall[idx[X]]-=ww[X];
    wall[idx[X]]+=V;
    ww[X]=V;
    return;
}
long long point_fatigue(std::vector<int> B){
    int p=B.size();
    int mn=INT_MAX,mx=INT_MIN, nl, nr;
    for(int i=0;i<p;++i){
        if(idx[B[i]]<mn){
            nl=B[i],mn=idx[B[i]];
        }
        if(idx[B[i]]>mx){
            nr=B[i],mx=idx[B[i]];
        }
    }
    ll l=idx[nl],r=idx[nr];
    ll wl=wall[l], wr=wall[r];
    // cout << l<<' '<<r << endl;
    ll ret = 0;
    while(l < r) {
        ll a=wl*1LL*abs(line[l]-line[l+1]);
        ll b=wr*1LL*abs(line[r]-line[r-1]);
        // cout<<wl<< ' '<<wr<<endl;
        // cout << l <<' ' <<r << ": " << a << ' ' << b << endl;
        // cout<<ret<<endl;
        if(a >= b) r--,ret+=b,wr+=wall[r];
        else l++,ret+=a,wl+=wall[l];
    }
    return ret;
}
long long interval_fatigue(std::vector<std::vector<int>> In){
    return 0;
}