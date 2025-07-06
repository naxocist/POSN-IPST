#include "symbols.h"
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
const ll mod = 20232566;
const int N = 8e4 + 3;
int n;
ll pw[N];
bool no = 0;
ll res = 0, sz = 0;
set<pi> s;


struct fenwick {
    int t[N];

    void upd(int i, int x) {
        for(;i<N; i+=i&-i) t[i] = max(t[i], x);
        return ;
    }

    int qry(int i) {
        int s = -1;
        for(;i>0; i-=i&-i) s = max(s, t[i]);
        return s;
    }
} fw;

void explore_site(int N, int Q) {
    n = N;
    sz = n;
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*26)%mod;
}


vector<bool> use(N);
int retrieve_notes(int l, int r) {
    l ++, r++;
    no = no or (r-l > 25);
    if(no) return 0;                                                                               
    if(fw.qry(l) > r) return res;

    auto it = s.lower_bound(pi(l, 0));
    while(it != s.end() and it->first <= r) {
        if(it->second <= r) it = s.erase(it);
        else it = s.lower_bound(pi(it->first+1, 0));
    }

    for(int i=l; i<=r; ++i) {
        if(use[i]) continue ;
        use[i] = 1;
        sz --;
    }
    s.insert(pi(l, r));
    fw.upd(l, r); 
    ll k = 1;

    for(auto it = s.begin(); it != s.end(); ++it) {
        if(it == s.begin()) {
            int c = 26;
            for(int i=it->first; i<=it->second; ++i) {
                k *= c--, k %= mod;
            }
        }else {
            if(it->first > prev(it)->second) {
                int c = 26;
                int len = it->second - it->first + 1;
                for(int i=it->first; i<=it->second; ++i) {
                    k *= c--, k %= mod;
                }
            }else {
                int c = 26 - (prev(it)->second - it->first + 1);
                for(int i=prev(it)->second+1; i<=it->second; ++i) {
                    k *= c--, k %= mod;
                }
            }
        }
    }
    // show(k)
    return res = (pw[sz]*k)%mod;
}