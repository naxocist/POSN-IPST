#include "stick.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
#define f first
#define s second
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 2e5 + 3;
vector<int> v;
int n;
using pv = pair<int, vector<int>>;
pv seg[4*N];

pv un(pv a, pv b) {
  int mx = max(a.f, b.f);
  vector<int> r;
  int i = 0, j = 0, idx = 0;

  while(i < a.s.size() and j < b.s.size()) 
  {
    if(a.s[i] > b.s[j]) r.pb(a.s[i]), i++;
    else r.pb(b.s[j]), j++;

    if(idx >= 2) 
    {
      if(r[idx-2] + r[idx-1] + r[idx] <= mx)
          return {mx, r};

      if(r[idx] + r[idx-1] > r[idx-2]) 
          return {r[idx-2]+r[idx-1]+r[idx], r};
    }
    idx ++;
  }

  while(i< a.s.size()) {
    r.pb(a.s[i]); i++;
    if(idx >= 2) {
      if(r[idx-2] + r[idx-1] + r[idx] <= mx)
          return {mx, r};
      if(r[idx] + r[idx-1] > r[idx-2]) 
          return {r[idx-2]+r[idx-1]+r[idx], r};
    }
    idx ++;
  }

  while(j < b.s.size()) {
    r.pb(b.s[j]), j++;

    if(idx >= 2) {
      if(r[idx-2] + r[idx-1] + r[idx] <= mx)
          return {mx, r};
      if(r[idx] + r[idx-1] > r[idx-2]) 
          return {r[idx-2]+r[idx-1]+r[idx], r};
    }
    idx ++;
  }
  return {mx, r};
}

void build(int i, int l, int r) {

  if(l == r) {
    seg[i] = {-1, {v[l]}};
    return ;
  }
  int m = l+(r-l)/2;
  build(2*i, l, m), build(2*i+1, m+1, r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

pv qry(int i, int l, int r, int x, int y) {
  if(r < x or l > y) return {-1, vector<int>()};
  if(x <= l and r <= y) return seg[i];
  int m = l+(r-l)/2;
  return un(qry(2*i, l, m, x, y), qry(2*i+1, m+1, r, x, y));
}


void init(int N, std::vector<int> X){
  n = N;
  v.resize(n+1);
  for(int i=1; i<=n; ++i) v[i] = X[i-1];
  build(1, 1, n);
  return;
}

int max_length(int l, int r){
  l ++, r++;
  pv res = qry(1, 1, n, l, r);
  return res.f;
}

