#include "sum_product.h"

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define ln '\n'

using ll = long long;
const int N = 1e5 + 3, mod = 1e9 + 7;

ll add(ll a, ll b) { return (a + b)%mod; }
ll mul(ll a, ll b) { return (a * b)%mod; }

int sum_product(int n, std::vector<int> a){

  vector<ll> twopw(n+1);

  twopw[0] = 1;
  for(int i=1; i<=n; ++i) twopw[i] = mul(twopw[i-1], 2);

  ll dp = 0, acc = 0, t = 0;
  for(int i=1; i<=n; ++i) {
    dp = acc;
    t = mul(t, a[i-1]) + mul(a[i-1], twopw[max(0, i-2)]);
    dp = add(dp, t);
    acc = add(dp, acc);
  }

	return dp;
}
