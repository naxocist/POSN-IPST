#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back

const int N = 2e5 + 3;
using ll = long long;
using pi = pair<ll, ll>;
ll qs[N], ar[N];
vector<pi> Q[N];

struct fenwick {
  ll ar[N], fw[N];

  void upd(int i, ll x) {
    ar[i] += x;
    for(++i;i<N;i+=i&-i) fw[i] += x;
  }

  ll qry(int i, ll s = 0) {
    for(++i;i>0;i-=i&-i) s += fw[i];
    return s;
  }

  void set(int i, ll x) {
    upd(i, x - ar[i]);
  }
} fw;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i], qs[i] = qs[i-1] + ar[i];

  for(int i=0; i<q; ++i) {
    int l, r; cin >> l >> r;
    Q[l].pb(r,i);
  }

  vector<ll> res(q);
  vector<pi> st;
  for(int l=n; l>=1; --l) {
    while(st.size() and ar[l] >= st.back().first) {
      st.pop_back();
      fw.set(st.size(), 0);
    }

    ll len = ((ll)st.size() ? st.back().second : n+1) - l;
    fw.set(st.size(), (ll)ar[l]*len);
    st.pb(ar[l], l);
    for(auto [r, k] : Q[l]) {
      // find left most index in st that is <= r 
      int L = -1, R = st.size();
      while (R - L > 1) {
        int md = L + (R-L)/2;
        if(st[md].second <= r) R = md;
        else L = md;
      }

      int valid = R;
      ll s1 = fw.qry(st.size() - 1) - fw.qry(valid);
      ll s2 = (ll)(r - st[valid].second + 1) * st[valid].first;
      ll pref = qs[r] - qs[l-1];
      res[k] = s1 + s2 - pref;
    }
  }

  for(auto x : res) cout << x << ln;
  return 0;
}
