#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back
#define all(x) begin(x), end(x)
using pi = pair<int, int>;
const int N = 2e5 + 3;
int seg[16*N], h[4*N], ar[N];
vector<int> ord;

int get(int x) {
  return lower_bound(all(ord), x) - ord.begin() + 1;
}

int get_u(int x) {
  return upper_bound(all(ord), x) - ord.begin() + 1;
}

void build(int i, int l, int r) {
  if(l == r) return void(seg[i] = h[l]);
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = seg[2*i] + seg[2*i+1];
}

void upd(int i, int l, int r, int p, int x) {
  if(l == r) return void(seg[i] += x);
  int md = l + (r-l)/2;
  if(p <= md) upd(2*i,l,md,p,x);
  else upd(2*i+1,md+1,r,p,x);
  seg[i] = seg[2*i] + seg[2*i+1];
}

int qry(int i, int l, int r, int a, int b) {
  if(a <= l and r <= b) return seg[i];
  if(r < a or l > b) return 0;
  int md = l + (r-l)/2;
  return qry(2*i,l,md,a,b) + qry(2*i+1,md+1,r,a,b);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  set<int> s;
  vector<pi> Q;
  for(int i=1; i<=n; ++i) cin >> ar[i], s.insert(ar[i]);
  while(q--) {
    char c; int a, b; cin >> c >> a >> b;
    if(c == '!') s.insert(b);
    Q.pb(c == '?' ? -a : a, b);
  }
  for(auto x : s) ord.pb(x);
  for(int i=1; i<=n; ++i) h[get(ar[i])] ++;

  n = (int)s.size();
  build(1,1,n);
  for(auto [a, b] : Q) {
    if(a<0) {
      a*=-1; 
      cout << qry(1,1,n,get(a),get_u(b)-1) << ln;
    }else {
      upd(1,1,n,get(ar[a]),-1);
      ar[a] = b;
      upd(1,1,n,get(ar[a]),1);
    }
  }
  return 0;
}
