#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ln '\n'
#define all(x) begin(x), end(x)

using pci = pair<char, int>;
const int N = 2e6 + 3;
int fw[N];
vector<int> t;
vector<pci> T;
int Q;

int get(int x) {
  // [1, Q]
  return lower_bound(all(t), x) - t.begin() + 1;
}

void upd(int i, int v) {
  for(;i<=Q; i+=i&-i) fw[i] += v;
}

int qry(int i) {
  int s = 0;
  for(;i>0; i-=i&-i) s += fw[i];
  return s;
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> Q;
  set<int> k;
  for(int i=0; i<Q; ++i){
    char c; int x; cin >> c >> x;
    k.insert(x);
    T.pb(c, x);
  }

  for(auto x : k) t.pb(x);

  for(auto [c, x] : T) {
    if(c == 'I') {
      int idx = get(x);
      if(qry(idx) - qry(idx-1) > 0) continue ;
      upd(idx, 1);
    }else if(c == 'O') {
      cout << qry(get(x) - 1) << ln;
    }else {
      x ++;
      int l = 0, r = Q+1;
      while(r - l > 1) {
        int md = l + (r-l)/2;
        if(qry(md) >= x) r = md;
        else l = md;
      }

      cout << t[r-1] << ln;
    }
  }

  return 0;
}
