#include <bits/stdc++.h>
using namespace std;

int n, k; 
vector<int> v;

bool ok(int l, int r, int cnt) {
  int len = r-l+1;
  if(len == 2) return true;

  int lf = 0, md = len / 2;
  for(int i=0; i<md; ++i) lf += v[l + i] == 1;

  if(abs(cnt - 2*lf) > 1) return false;

  return ok(l,l+md-1,lf) and ok(l+md,r,cnt-lf);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;

  while(n--) {
    int cnt = 0;
    v.clear();
    for(int i=0; i<1<<k; ++i) {
      int x; cin >> x;
      v.emplace_back(x);
      cnt += x;
    }

    cout << (ok(0,(1<<k)-1,cnt) ? "yes" : "no") << '\n';
  }

  return 0;
}
