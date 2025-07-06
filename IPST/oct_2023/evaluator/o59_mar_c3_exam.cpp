#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 5e4 + 3;
int ar[N], fw[N];
vector<pi> go[N];
unordered_map<int, int> um;

void upd(int i, int x) {
    for(;i<N;i+=i&-i) fw[i] += x;
    return ;
}

int qry(int i) {
    int s = 0;
    for(;i;i-=i&-i) s += fw[i];
    return s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >>n;
    for(int i=1; i<=n; ++i) cin >> ar[i];

    int q; cin >> q;
    for(int i=0; i<q; ++i){
        int l, r; cin >> l >> r; l++, r++;
        go[l].pb(i, r);
    }

    vector<int> res(q);
    for(int i=n; i>=1; --i) {
        if(um[ar[i]]) upd(um[ar[i]], -1);
        um[ar[i]] = i;
        upd(i, 1);
        for(auto e : go[i]) {
            int t, r; tie(t, r) = e;
            res[t] = r-i+1-qry(r);
        }
    }

    for(auto x : res) cout << x << '\n';
    return 0;
}
