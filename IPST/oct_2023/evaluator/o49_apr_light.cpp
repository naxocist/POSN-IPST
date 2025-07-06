#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e5 + 3;
int ar[N], seg[4*N], qs[N];
bool lz[4*N];
unordered_map<int, int> um;

void pushlz(int i, int l, int r) {
    if(!lz[i]) return ;
    lz[i] = 0;
    seg[i] = qs[r] - qs[l-1] - seg[i];
    if(l != r) lz[2*i] = !lz[2*i], lz[2*i+1] = !lz[2*i+1];
}


void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = qs[l] - qs[l-1];
        return ;
    }
    int md = l+(r-l)/2;
    build(2*i, l, md), build(2*i+1, md+1, r);
    seg[i] = seg[2*i] + seg[2*i+1];
}

void upd(int i, int l, int r, int x, int y) {
    pushlz(i, l, r);
    if(r < x || l > y) return ;
    if(x <= l && r <= y) {
        lz[i] = 1;
        pushlz(i, l, r);
        return ;
    }
    int md = l+(r-l)/2;
    upd(2*i, l, md, x, y), upd(2*i+1, md+1, r, x, y);
    seg[i] = seg[2*i] + seg[2*i+1];
} 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int l, n; cin >> l >> n;

    for(int i=1; i<=n; ++i) {
        cin >> ar[i];
        qs[i] = ar[i];
    }
    sort(qs+1, qs+n+1);
    qs[n+1] = l;
    for(int i=1; i<=n; ++i) um[qs[i]] = i;
    build(1, 1, n+1);
    for(int i=1; i<=n; ++i) {
        upd(1, 1, n+1, um[ar[i]]+1, n+1);
        cout << seg[1] << '\n';
    }

    return 0;
}
