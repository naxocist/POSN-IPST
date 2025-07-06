#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ln '\n'

using ll = long long;
const int N = 2e5 + 3;
int ar[N];

struct segtree {
  struct node {
    ll sum = 0, lz_set = 0, lz_add = 0;
    bool set_valid = 0;

    void reset() {
      lz_set = set_valid = lz_add = 0;
    }

  } t[4*N];

  void build(int i, int l, int r) {
    if(l == r) return void(t[i].sum = ar[l]);
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i].sum = t[2*i].sum + t[2*i+1].sum;
  }

  // apply
  void apply(int i, int l, int r) {
    if(t[i].set_valid) t[i].sum = (r-l+1)*t[i].lz_set; 
    t[i].sum += (r-l+1)*t[i].lz_add;
    if(l != r) push(i,2*i), push(i,2*i+1);
    
    t[i].reset();
  }

  // compose
  void push(int par, int ch) {
    if(t[par].set_valid) t[ch] = t[par];
    else t[ch].lz_add += t[par].lz_add;
  }


  ll qry(int i, int l, int r, int a, int b) {
    apply(i,l,r);
    if(r < a or l > b) return 0;
    if(a <= l and r <= b) return t[i].sum;
    int md = l + (r-l)/2;
    return qry(2*i,l,md,a,b) + qry(2*i+1,md+1,r,a,b);
  }

  void set(int i, int l, int r, int a, int b, int x) {
    apply(i,l,r);
    if(r < a or l > b) return ;
    if(a <= l and r <= b) {
      t[i].set_valid = 1;
      t[i].lz_set = x;
      t[i].lz_add = 0;
      apply(i,l,r);
      return ;
    }
    int md = l + (r-l)/2;
    set(2*i,l,md,a,b,x); set(2*i+1,md+1,r,a,b,x);
    t[i].sum = t[2*i].sum + t[2*i+1].sum;
  }

  void add(int i, int l, int r, int a, int b, int x) {
    apply(i,l,r);
    if(r < a or l > b) return ;
    if(a <= l and r <= b) {
      t[i].lz_add += x; 
      apply(i,l,r);
      return ;
    }
    int md = l + (r-l)/2;
    add(2*i,l,md,a,b,x); add(2*i+1,md+1,r,a,b,x);
    t[i].sum = t[2*i].sum + t[2*i+1].sum;
  }

} seg;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> ar[i];
  }

  seg.build(1,1,n);
  while(q--) {
    int c, a, b, x; cin >> c;
    if(c == 1) {
      cin >> a >> b >> x;
      seg.add(1,1,n,a,b,x);
    }else if(c == 2) {
      cin >> a >> b >> x;
      seg.set(1,1,n,a,b,x);
    }else {
      cin >> a >> b; cout << seg.qry(1,1,n,a,b) << ln;
    }
  }
  return 0;
}
