#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;

struct node {
    int pre = 0, suf = 0, mid = 0, sum = 0;
};

vector<node> seg(4*N);
vector<int> v;
node no;

node un(node a, node b) {
    node t ;
    t.pre = max(a.pre, a.sum + b.pre);
    t.suf = max(b.suf, b.sum + a.suf);
    t.mid = max({a.suf + b.pre, a.mid, b.mid});
    t.sum = a.sum + b.sum;

    return t;
}

void build(int i, int l, int r) {
    if(l == r) {
        seg[i].pre = seg[i].suf = seg[i].mid = seg[i].sum = v[l];
        return ;
    }

    int md = (l+r)>>1;
    build(2*i, l, md); build(2*i+1, md+1, r);
    seg[i] = un(seg[2*i], seg[2*i+1]);
    return ;
}

node query(int i, int l, int r, int tl, int tr) {
    if(r < tl || l > tr) return no;

    if(tl <= l && r <= tr) return seg[i];
    
    int md = (l+r)>>1;
    return un(query(2*i, l, md, tl, tr), query(2*i+1, md+1, r, tl, tr));
}   

int main() {
    int n, q; scanf("%d%d", &n, &q);
    v.resize(n);
    for(int i=0; i<n; ++i)  scanf("%d", &v[i]);

    build(1, 0, n-1);
    while(q--) {
        int l, r; scanf("%d%d", &l, &r); 
        node res = query(1, 0, n-1, l, r);
        printf("%d\n", max({res.pre, res.suf, res.mid, res.sum}));
    }
}
