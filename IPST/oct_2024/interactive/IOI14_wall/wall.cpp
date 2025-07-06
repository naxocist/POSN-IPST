#include "wall.h"
#include <bits/stdc++.h>
using namespace std;

#define INF 2e9
const int N = 2e6 + 3;
struct node {
  int val, lzmn, lzmx;
  node(): val(0), lzmn(INF), lzmx(-INF) {}
} seg[4*N];

int n;

void push(int i, int l, int r) {
  seg[i].val = min(seg[i].val, seg[i].lzmn);
  seg[i].val = max(seg[i].val, seg[i].lzmx);

  int mn = seg[i].lzmn, mx = seg[i].lzmx;

  if(l != r) {
    seg[2*i].lzmn = min(seg[2*i].lzmn, mn);
    seg[2*i+1].lzmn = min(seg[2*i+1].lzmn, mn);
    seg[2*i].lzmn = max(seg[2*i].lzmn, mx);
    seg[2*i+1].lzmn = max(seg[2*i+1].lzmn, mx);
    seg[2*i].lzmx = max(seg[2*i].lzmx, mx);
    seg[2*i+1].lzmx = max(seg[2*i+1].lzmx, mx);
    seg[2*i].lzmx = min(seg[2*i].lzmx, mn);
    seg[2*i+1].lzmx = min(seg[2*i+1].lzmx, mn);
  }

  seg[i].lzmn = INF, seg[i].lzmx = -INF;
}

void upd(int a, int b, int mn, int mx, int i = 1, int l = 1, int r = n) {
  push(i,l,r);
  if(a <= l and r <= b) {
    seg[i].lzmx = mx;
    seg[i].lzmn = mn;
    push(i,l,r);
    return ;
  }
  if(r < a or l > b) return ;
  int md = l + (r-l)/2;
  upd(a,b,mn,mx,2*i,l,md); upd(a,b,mn,mx,2*i+1,md+1,r);
}

int qry(int p, int i = 1, int l = 1, int r = n) {
  push(i,l,r);
  if(l == r) return seg[i].val;
  int md = l + (r-l)/2;
  if(p <= md) return qry(p,2*i,l,md);
  return qry(p,2*i+1,md+1,r);
}

void buildWall(int N, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  n = N;

  for(int i=0; i<k; ++i) {
    int l = left[i], r = right[i], o = op[i], h = height[i]; l++, r++;
    int mn, mx;
    if(o == 1) upd(l,r,INF,h); // add
    else upd(l,r,h,-INF); // rem
  }

  for(int i=0; i<n; ++i) {
    finalHeight[i] = qry(i+1);
  }
  return;
}

