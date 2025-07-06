#include "stick.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 2e5 + 3;
int ar[N];
int n;

struct node {
  int mx;
  vector<int> v;
} seg[4*N];

node un(node a, node b) {
  int mx = max(a.mx, b.mx);

  vector<int> nw;
  int l = 0, r = 0;
  while(l < a.v.size() and r < b.v.size()) {
    if(a.v[l] > b.v[r]) nw.pb(a.v[l++]);
    else nw.pb(b.v[r++]);
    if(nw.size() >= 3) {
      int last = nw.size()-1;

      if(nw[last-1] + nw[last] > nw[last-2]) 
        return {nw[last-1] + nw[last-2] + nw[last], nw}; 
    }
  }

  while(l < a.v.size()) {
    nw.pb(a.v[l++]);
    if(nw.size() >= 3) {
      int last = nw.size()-1;
      if(nw[last-1] + nw[last] > nw[last-2]) 
        return {nw[last-1] + nw[last-2] + nw[last], nw}; 
    }
  }

  while(r < b.v.size()) {
    nw.pb(b.v[r++]);
    if(nw.size() >= 3) {
      int last = nw.size()-1;
      if(nw[last-1] + nw[last] > nw[last-2]) 
        return {nw[last-1] + nw[last-2] + nw[last], nw}; 
    }
  }
  return {-1, nw};
}

void build(int i, int l, int r) {
  if(l == r) {
    seg[i].mx = -1;
    seg[i].v = {ar[l]};
    return ;
  }
  int md = l + (r-l)/2; 
  build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = un(seg[2*i], seg[2*i+1]);
}

node qry(int i, int l, int r, int a, int b) {
  if(a <= l and r <= b) return seg[i];
  if(r < a or l > b) return {-1, vector<int>()};
  int md = l + (r-l)/2;
  return un(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
}

void init(int N, std::vector<int> X){
  n = N;
  for(int i=1; i<=n; ++i) ar[i] = X[i-1];
  build(1,1,n);
  return;
}

int max_length(int L,int R){
  L++,R++;
  return qry(1,1,n,L,R).mx;
}
