#include "guess.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

using pi = pair<int, char>;

int find_answer(int n, int k) {

  vector<int> can;
  for(int i=0; i<n; ++i) can.push_back(i);

  if(k == 1 and n == 1024) {
    int l = 0, r = n-1, res = -1;
    while(l <= r) {
      int md = l + (r-l)/2;
      if(l == r) return l;

      vector<pi> t;
      for(int i=0; i<=md; ++i) { t.pb(i,'R'); }
      if(ask(t) == 'R') r = md;
      else l = md + 1;
    }
  }else if(n % 3 == 0) {
    vector<int> res;
    for(int i=0; i<n; ++i) res.pb(i);

    while(res.size() > 1) {
      vector<pi> t;
      for(int i=0; i<2*n/3; i+=2) t.pb(res[i], 'R');
      for(int i=0; i<res[2*n/3-1]; ++i) {
        if(find(res.begin(), res.end(), i) == res.end()) t.pb(i, 'R');
      }

      sort(t.begin(), t.end());
      char a = ask(t);
      vector<int> y;
      if(a == 'X') {
        for(int i=2*n/3; i<n; ++i) y.pb(res[i]);
      }else if(a == 'R') {
        for(int i=0; i<2*n/3; i+=2) y.pb(res[i]);
      }else {
        for(int i=1; i<2*n/3; i+=2) y.pb(res[i]);
      }

      res = y;
      n/=3;
    }

    return res[0];
  }else {
  }
  return 1;
}
