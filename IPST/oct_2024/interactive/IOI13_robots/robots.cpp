#include "robots.h"
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using pi = pair<int, int>;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {

  // sort robots
  sort(X, X+A);
  sort(Y, Y+B, greater<int>());
  vector<pi> v; for(int i=0; i<T; ++i) v.pb(W[i], S[i]);
  sort(v.begin(), v.end());

  int l = 0, r = 1e6 + 1;
  while(l + 1 < r) {
    int md = l + (r-l)/2;

    priority_queue<int> pq;
    int j = 0;
    for(int i=0; i<A; ++i) {
      for(;j<T; ++j) {
        int w, s; tie(w, s) = v[j];
        if(w >= X[i]) break ; 
        pq.emplace(s);
      }
      int c = 0;
      while(pq.size() and c + 1 <= md) c ++, pq.pop();
    }

    for(;j<T; ++j) pq.emplace(v[j].second);
    for(int i=0; i<B; ++i) {
      int c = 0;
      while(pq.size() and pq.top() < Y[i] and c + 1 <= md) c ++, pq.pop();
    }

    if(pq.empty()) r = md;
    else l = md;
  }

  return r == 1e6 + 1 ? -1 : r;
}
