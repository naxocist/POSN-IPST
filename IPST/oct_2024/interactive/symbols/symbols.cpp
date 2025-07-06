#include "symbols.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 20232566;
const int N = 8e4 + 3;
int n;
ll mul(ll a, ll b) { return (a*b)%mod; }

struct segtree {
  ll t[4*N];
  void build(int i, int l, int r) {
    if(l == r) return void(t[i] = 26);
    int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
    t[i] = mul(t[2*i], t[2*i+1]);
  }

  ll qry(int i, int l, int r, int a, int b) {
    if(a <= l and r <= b) return t[i];
    if(r < a or l > b) return 1;
    int md = l + (r-l)/2;
    return mul(qry(2*i,l,md,a,b), qry(2*i+1,md+1,r,a,b));
  }

  void upd(int i, int l, int r, int p, int v) {
    if(l == r) return void(t[i]=v);
    int md = l + (r-l)/2;
    if(p <= md) upd(2*i,l,md,p,v);
    else upd(2*i+1,md+1,r,p,v);
    t[i] = mul(t[2*i], t[2*i+1]);
  }
} seg;

void explore_site(int N, int Q) {
  n = N;
  seg.build(1,1,n);
}

int far[N];
bool chk = false;
int retrieve_notes(int L, int R) {
  if(R-L+1 > 26) chk = true;
  if(chk) return 0;

  for(int i=L; i<=R; ++i) {
    far[i] = max(far[i], i - L);
    seg.upd(1,1,n,i,max(0, 26-far[i]));
  }
  return seg.t[1];
}
