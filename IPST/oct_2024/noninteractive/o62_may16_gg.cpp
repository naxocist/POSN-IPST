#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ln '\n'

const int N = 51;
ll bin[N];

ll dt(ll x, int k) { return bin[k] - 1 - x; }
ll db(ll x, int k) { return x}
ll dl(ll x, int k) { return x; }
ll dr(ll x, int k) { return bin[k] - 1 - x; }

ll norm(ll x, int k) {
  return (x >= bin[k] ? x - bin[k] : x);
}

int q(ll x, ll y, int k) {
  bool bx = x < bin[k], by = y < bin[k];
  if(bx and !by) return 1;
  if(!bx and !by) return 2;
  if(bx and by) return 3;
  return 4;
}

ll f(ll k, ll x, ll y, ll a, ll b) {
  if(k == 0) return 0;

  int q1 = q(x,y,k), q2 = q(a,b,k);
  if(q1 > q2) swap(q1, q2), swap(x, a), swap(y, b);

  ll nx = norm(x,k-1);
  ll ny = norm(y,k-1);
  ll na = norm(a,k-1);
  ll nb = norm(b,k-1);

  if(q1 == q2) return f(k-1,nx,ny,na,nb);
  if(q1 == 1 and q2 == 2) return f(k-1,nx,ny,nx,bin[k-1]-1) + f(k-1,na,nb,na,bin[k-1]-1) + a - x;
  if(q1 == 2 and q2 == 3) return dr(x,k) + dr(a,k) + y - b;
  if(q1 == 3 and q2 == 4) return db(y,k) + db(b,k) + a - x;
  if(q1 == 1 and q2 == 4) return dl(x,k) + dl(a,k) + y - b;

  // if(q1 == 1 and q2 == 4) return dt(y,k) + x + bin[k] + a + db(b,k);
  if(q1 == 3 and q2 == 2) return x + 
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k, x, y, a, b; cin >> k >> x >> y >> a >> b;

  bin[0] = 1;
  for(int i=1; i<=50; ++i) bin[i] = bin[i-1] * 2;
  cout << f(k, x, y, a, b) << ln;
  return 0;
}
