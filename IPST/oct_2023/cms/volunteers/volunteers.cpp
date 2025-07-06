#include "volunteers.h"
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

const int N = 2e4 + 3, M = 403;
int ar[N][M], dp[N];
int n, m, q;

struct segtree {
    int t[N], lz[N];

    void upd(int i, int l, int r, int x, int v) {
        if(x < l or x > r) return ;
        if(l == r) {
            t[i] = v-l;
            return ;
        }
        int m =(l+r)/2;
        upd(2*i, l, m, x, v); upd(2*i+1, m+1, r, x, v);
        t[i] = max(t[2*i], t[2*i+1]);
    }

    int qry(int i, int l, int r, int x, int y) {
        if(r < x or l > y) return 0;
        if(x <= l and r <= y) return t[i];
        int m =(l+r)/2;
        int a = qry(2*i, l, m, x, y); int b= qry(2*i+1, m+1, r, x, y);
        // t[i] = max(t[2*i], t[2*i+1]);
        return max(a, b);
    }
}seg;
void setup_battalion(int N, int M, int Q, std::vector<std::vector<int>> H) {
    n=N,m=M,q=Q;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            ar[i][j] = H[i-1][j-1];
        }
    }
    ar[0][1] = ar[1][1];

    int mx = 0, prv = 1;
    for(int i=1; i<=n; ++i) {
        if(ar[i][1] > ar[i-1][1]) {
            for(int j=prv; j<=i-1; ++j) seg.upd(1, 1, n, j, i);
            mx = 1;
            prv = i;
        }else {
            mx ++;
        }
    }

    for(int j=prv; j<=n; ++j) seg.upd(1, 1, n, j, mx);


}
int count_volunteers(int L, int R) { 
    L++, R++;
    
    return seg.qry(1, 1, n, L, R);
}
