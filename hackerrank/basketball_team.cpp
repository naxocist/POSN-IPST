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


bool check(vector<int> v, int n, long long p, long long m){
  long long ind = 0;
  while (p > 0) {
    if (ind >= n) return false;
    p -= (m / v[ind]);
    ind++;
  }
  return true;
}



int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  ll p;
  cin >> n >> p;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());

  ll l = 0, r = 1e12, res = 1e12;

  while (l <= r) {
    long long md = l + (r - l) / 2;
    if (check(v, n, p, md)) r = md - 1, res = min(res, md);
    else l = md + 1;
  }

  cout << res;
  return 0;
}