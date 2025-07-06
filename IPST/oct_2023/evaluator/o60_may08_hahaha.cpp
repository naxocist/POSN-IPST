#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "===========\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

mt19937 rng(time(0));

struct box {
    ll inv;
    ll freq[5];
    box() {
        inv = 0;
        for(int i=0; i<5; ++i) freq[i] = 0;
    }
    box(int v) {
        inv = 0;
        for(int i=0; i<5; ++i) freq[i] = 0;
        freq[v] ++;
    }

    friend box operator+(box l, box r) {
        l.inv += r.inv;
        ll s = 0;
        for(int i=0; i<5; ++i) {
            l.inv += s*l.freq[i];
            s += r.freq[i];
        }
        for(int i=0; i<5; ++i) l.freq[i] += r.freq[i];
        return l;
    }

    void flip() {
        ll s = 0;
        for(int i=0; i<5; ++i) s += freq[i];
        s = s*(s-1)/2;
        for(int i=0; i<5; ++i) s -= freq[i]*(freq[i]-1)/2;
        inv = s - inv;
    }

    void set(ll x) {
        ll s = 0;
        for(int i=0; i<5; ++i) s += freq[i], freq[i] = 0;
        freq[x] = s;
        inv = 0;
    }
};

struct treap {
    struct node {
        box val;
        ll sz, pr, lz, num;
        bool flip;
        node *l, *r;
        node(int x) : num(x), val(box(x)), pr(rng()), flip(0), sz(1), lz(-1), l(nullptr), r(nullptr) {}
    };
    node *root = nullptr;

    ll sz(node *t) {
        return t ? t->sz : 0;
    }

    box val(node *t) {
        return t ? t->val : box();
    }
    void upd(node *t) {
        if(!t) return ;
        pushlz(t->l);
        pushlz(t->r);
        t->sz=sz(t->l)+1+sz(t->r);
        t->val=val(t->l)+box(t->num)+val(t->r);
    }

    void pushlz(node *t) {
        if(t and t->lz != -1) {
            t->val.set(t->lz);
            t->num = t->lz;
            if(t->l) t->l->lz = t->lz;
            if(t->r) t->r->lz = t->lz;
            t->lz = -1;
        }

        if(t and t->flip) {
            t->flip = 0;
            t->val.flip();
            swap(t->l, t->r);
            if(t->l) t->l->flip ^= 1;
            if(t->r) t->r->flip ^= 1;
        }
    }

    void split(node *t, node *&l, node *&r, int x) {
        pushlz(t);
        if(!t) return void(l = r = nullptr);
        if(sz(t->l) + 1 <= x) split(t->r, t->r, r, x - sz(t->l) - 1), l = t;
        else split(t->l, l, t->l, x), r = t;
        upd(t);
    }

    void merge(node *&t, node *l, node *r) {
        pushlz(l), pushlz(r);
        if(!l) return void(t = r);
        if(!r) return void(t = l);
        if(l->pr > r->pr) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
        upd(t);
    }

    void rev(int l, int r) {
        node *a, *b, *c, *d;
        split(root, a, b, l-1);
        split(b, c, d, r-l+1);
        pushlz(c);
        c->flip ^= 1;
        merge(root, a, c);
        merge(root, root, d);
    }

    void set(int l, int r, int z) {
        node *a, *b, *c, *d;
        split(root, a, b, l-1);
        split(b, c, d, r-l+1);
        pushlz(c);
        c->lz = z;
        pushlz(c);
        merge(root, a, c);
        merge(root, root, d);
    }

    ll inv(int l, int r) {
        node *a, *b, *c, *d;
        split(root, a, b, l-1);
        split(b, c, d, r-l+1);
        pushlz(c); upd(c);
        ll ret = c->val.inv;
        merge(root, a, c);
        merge(root, root, d);
        return ret;
    }

     void insert(int x) {
        merge(root, root, new node(x));
    }
} t;

int n, q; string s;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;

    for(char c : s) t.insert(c-'0');

    while(q--) {
        int c, x, y, z; cin >> c;
        if(c == 1) {
            cin >> x >> y >> z;
            t.set(x, y, z);
        }else if(c == 2) {
            cin >> x >> y;
            t.rev(x, y);
        }else {
            cin >> x >> y;
            cout << t.inv(x, y) << '\n';
        }
    }
    return 0;
}
