#include "longest.h"
#include <bits/stdc++.h>
using namespace std;
#define ln '\n'


std::vector<std::pair<int,int>> longest(int n) {
  // find(a, b, x) 
  using pi = pair<int, int>;
  #define pb emplace_back
  vector<pi> res = {{0, 0}, {0, 1}};

  if(find(0, 1, 2)) res.pb(1, 2);
  else res.pb(0, 2);

  for(int i=3; i<n; ++i) {
    int x, y; tie(x, y) = res.back();
    if(find(x, y, i)) {
      if(find(x, i, y)) x = i;
    }else {
      if(find(y, i, x)) y = i;
    }

    res.pb(x, y);
  }

  return res;
}
