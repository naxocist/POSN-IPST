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

#include "coin.h"

const int N = 2e5 + 3, M = 1e6 + 3;
priority_queue<pi> pq;
int qs[N], cover[N], cnt[N];
int n, L;

struct fenwick {
    int t[M] = {0};

    void upd(int i, int x) {
        for(; i<M; i+=i&-i) t[i] += x;
        return ;
    }

    int qry(int i) {
        int s = 0;
        for(; i>0; i-=i&-i) s += t[i];
        return s;
    }

} fw;

struct segtree {
    int t[M] = {0}, lz[M] = {0};
    void pushlz(int i, int l, int r) {
        if(!lz[i]) return ;
        t[i] += lz[i];
        if(l != r) lz[2*i] += lz[i], lz[2*i+1] += lz[i];
        lz[i] = 0;
    }
    void upd(int i, int l, int r, int x, int y, int v) {
        pushlz(i, l, r);
        if(r < x or l > y) return ;
        if(x <= l and r <= y)  {
            lz[i] += 1;
            pushlz(i, l, r);
            return ;
        }
        int md = l+(r-l)/2;
        upd(2*i, l, md, x, y, v), upd(2*i+1, md+1, r, x, y, v);
        t[i] = max(t[2*i], t[2*i+1]);
    }

    int qry(int i, int l, int r, int x, int y) {
        pushlz(i, l, r);
        if(r < x or l > y) return 0;
        if(x <= l and r <= y) return t[i];
        int md = l+(r-l)/2;
        return max(qry(2*i, l, md, x, y), qry(2*i+1, md+1, r, x, y));
    }
} seg;

void initialize(int N, vector<int> rail,int L)
{
    n = N, ::L = L;
    for(int i=1; i<=n; ++i) pq.emplace(rail[i-1], i);
    return;
}

vector<int> max_dist(vector<vector<int>> coins)
{
    int q = coins.size();
    vector<int> res(q);
    map<int, vector<int>> sz;
    for(int i=0; i<q; ++i) {
        int c = coins[i][2];
        sz[c].pb(i);
    }
    auto it = sz.end();
    
    do {
        it--;
        int c = (*it).first;
        while(pq.size() and pq.top().first > c) {
            int j = pq.top().second;
            fw.upd(j, 1);
            seg.upd(1, 1, n, max(1, j-L+1), j, 1);
            pq.pop();
        }

        // for(int i=1; i<=n; ++i) cout << seg.qry(1, 1, n, i, i) << ' ';
        // cout << endl;
        // cout << seg.qry(1, 1, n, 2, 6) << endl;
        for(auto i : (*it).second) {
            int a = coins[i][0], b = coins[i][1];
            a ++;

            int l = a, r = n, can = a-1;
            while(l <= r) {
                int md = l + (r-l)/2;
                int holes = fw.qry(md) - fw.qry(a-1);
                if(holes <= b) l = md + 1, can = md;
                else r = md - 1;
            }
            can ++;
            // show(i)
            // cout << a << ' ' << can << endl;
            int tape = seg.qry(1, 1, n, a, can);
            // show(tape)
            // cout << a+L-1 << ' ' << can-L+1 << endl;
            l = a, r = n, can = a-1;
            while(l <= r) {
                int md = l + (r-l)/2;
                int holes = fw.qry(md) - fw.qry(a-1);
                if(holes <= b + tape) l = md + 1, can = md;
                else r = md - 1;
            }
            
            res[i] = can;
            // div()
        }
    } while(it != sz.begin());
    return res;
}