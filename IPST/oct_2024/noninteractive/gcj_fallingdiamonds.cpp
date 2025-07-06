#include <bits/stdc++.h>
using namespace std;


#define double long double
using ll = long long;
using ull = unsigned long long;
const int N = 5e3 + 3;
double C[N][N];

ll cal(ll x) {
  return x*(2*x - 1);
}

double f(ll n, ll x, ll y) {
  x = abs(x);

  ll lvl = (x + y)/2 + 1;

  if(n >= cal(lvl)) return 1.0;

  if(x == 0) return 0.0;

  // x != 0
  ll left = n - cal(lvl-1); // cal(lvl-1) < left < cal(lvl)
  if(left <= 0) return 0.0;
  if(left >= (lvl-1)*2 + y+1) return 1.0;

  double res = 0;
  for(int i=y+1; i<=left; ++i) {
    res += C[left][i];
  }

  for(int i=0; i<left; ++i) res *= 0.5L;;
  return res;
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  for(int i=0; i<N; ++i) {
    for(int j=0; j<=i; ++j) {
      if(j == 0 or j == i) {
        C[i][j] = 1ULL; continue ;
      }
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  int T; cin >> T;
  for(int i=1; i<=T; ++i) {
    ll n, x, y; cin >> n >> x >> y;
    printf("Case #%d: %.16Lf\n", i, f(n,x,y));
  }
  return 0;
}
