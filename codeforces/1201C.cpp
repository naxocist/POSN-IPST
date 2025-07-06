#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template <typename S, typename T>
S amax(S &a, const T &b)
{
  if (b > a)
    a = b;
  return a;
}
template <typename S, typename T>
S amin(S &a, const T &b)
{
  if (b < a)
    a = b;
  return a;
}

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int)(x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;

void runcase()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v)
    cin >> x;
  sort(all(v));

  int l = v[n / 2] - 1, r = 2e9 + 1;
  while (l + 1 < r) {
    int md = l + (r - l) / 2;

    ll cnt = 0;
    for (int i = n / 2; i < n; ++i) {
      cnt += max(0, md - v[i]);
    }

    // dbg(md, cnt);
    if (cnt <= k) l = md;
    else r = md;
  }

  cout << l;
  return;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC;
  while (TC--)
    runcase();
  return 0;
}