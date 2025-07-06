#include <bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
const int N = 2e5 + 3;
using ll = long long;
struct pt {
  ll x, y;
} p[N];
 
ll dist(pt a, pt b) {
  ll dx = a.x-b.x, dy = a.y-b.y;
  return dx*dx + dy*dy;
}
 
 
ll closest(int l, int r) {
  if(l == r) return LLONG_MAX;
 
  int md = l + (r-l)/2, len = r-l+1;
  pt midp = p[md];
  ll c = min(closest(l,md), closest(md+1,r));
 
  auto cmpy = [&](pt &a, pt &b) { return a.y < b.y; };
  pt tmp[len];
  merge(p+l, p+md+1, p+md+1, p+r+1, tmp, cmpy);
  copy(tmp, tmp+len, p+l);
 
  // p[l,r] is now sorted by y value in ascending fashion
  ll res = c;
 
  int sz = 0;
  for(int i=l; i<=r; ++i) {
    ll d = abs(p[i].x - midp.x);
    if(d*d < c) {
      for(int j=sz-1; j>=0 and p[i].y - tmp[j].y < res; j--) {
        res = min(res, dist(p[i], tmp[j]));
      }
      tmp[sz++] = p[i];
    }
  }
 
  return res;
}
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) cin >> p[i].x >> p[i].y;
 
  auto cmp = [&](pt a, pt b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  };
  sort(p, p+n, cmp);
  cout << closest(0,n-1) << '\n';
  return 0;
}
