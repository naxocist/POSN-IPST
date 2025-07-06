#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int h[N], a[N], k[N], b[N];
int s1[4*N], s2[4*N];

void build(int i, int l, int r) {
  if(l == r) {
    s1[i] = b[l] + k[l];
    s2[i] = b[l] - k[l];
    return ;
  }
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  s1[i] = max(s1[2*i], s1[2*i+1]);
  s2[i] = max(s2[2*i], s2[2*i+1]);
}

int qry(int i, int l, int r, int a, int b, int op) {
  if(a <= l and r <= b) return (op == 1 ? s1[i] : s2[i]);
  if(r < a or l > b) return -2e9;
  int md = l + (r-l)/2;
  return max(qry(2*i,l,md,a,b,op), qry(2*i+1,md+1,r,a,b,op));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) cin >> h[i] >> a[i];
  for(int i=1; i<=n; ++i) cin >> k[i] >> b[i];

  build(1,1,n);
  for(int i=1; i<=n; ++i) {
    int H = h[i], A = a[i];
    int t = upper_bound(k+1,k+1+n, H) - k;
    int lf = A - H + qry(1,1,n,1,t-1,1), rt = A + H + qry(1,1,n,t,n,2);
    cout << max(lf, rt) << '\n';
  }
  return 0;
}
