#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 2e5 + 3;
int seg[4*N], ar[N];

void build(int i, int l, int r) {
  if(l == r) return void(seg[i] = 1);
  int md = l + (r-l)/2; build(2*i,l,md); build(2*i+1,md+1,r);
  seg[i] = seg[2*i] + seg[2*i+1];
}

void upd(int i, int l, int r, int x) {
  if(l == r) {
    cout << ar[l] << ' ';
    seg[i] --;
    return ;
  }
  int md = l + (r-l)/2;
  if(seg[2*i] >= x) upd(2*i,l,md,x); 
  else upd(2*i+1,md+1,r,x - seg[2*i]);
  seg[i] = seg[2*i] + seg[2*i+1];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) cin >> ar[i];
  build(1,1,n);
  int k = n;
  while(k--) {
    int x; cin >> x;
    upd(1,1,n,x);
  }

  return 0;
}
