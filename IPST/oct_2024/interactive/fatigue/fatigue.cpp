#include <vector>
#include "fatigue.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 3, K = 20;
int coor[N], a[N], w[N], pos[N];
int spmn[K][N], spmx[K][N];
int n;

struct fenwick {
  ll fw[N];
  void add(int i, ll x) {
    for(;i<N;i+=i&-i)fw[i]+=x;
  }
  ll qry(int i, ll s=0) {
    for(;i>0;i-=i&-i)s+=fw[i]; return s;
  }
} fw1, fw2;


int get_mx(int l, int r) {
  int lg = log2(r-l+1);
  return max(spmx[lg][l], spmx[lg][r-(1<<lg)+1]);
}

int get_mn(int l, int r) {
  int lg = log2(r-l+1);
  return min(spmn[lg][l], spmn[lg][r-(1<<lg)+1]);
}

ll cal(int l, int r) {
  ll vl = fw1.qry(l-1), vr = fw1.qry(r);
  ll vl2 = fw2.qry(l-1), vr2 = fw2.qry(r);
  ll tar = (vl + vr + 1)/2;

  int L = l-1, R = r+1;
  while(R-L > 1) {
    int md = L + (R-L)/2;
    if(fw1.qry(md) >= tar) R = md;
    else L = md;
  }

  int mid = R;
  ll vm = fw1.qry(mid), vm2 = fw2.qry(mid);
  return (vr2-vm2) - (vr-vm)*coor[mid] + (vm-vl)*coor[mid] - (vm2-vl2);
}

void initialize(int N, std::vector<int> A, std::vector<int> W){
  n = N;
  for(int i=1; i<=n; ++i) w[i] = W[i-1], coor[i] = a[i] = A[i-1];
  sort(coor+1,coor+1+n);

  for(int i=1; i<=n; ++i) {
    pos[i] = spmn[0][i] = spmx[0][i] = lower_bound(coor+1,coor+1+n,a[i]) - coor;
    fw1.add(pos[i],(ll)w[i]);
    fw2.add(pos[i],(ll)w[i]*a[i]);
  }

  for(int i=1; i<K; ++i) {
    for(int j=1; j+(1<<i)-1<=n; ++j) {
      spmn[i][j] = min(spmn[i-1][j], spmn[i-1][j+(1<<(i-1))]);
      spmx[i][j] = max(spmx[i-1][j], spmx[i-1][j+(1<<(i-1))]);
    }
  }

  return;
}
void change_weight(int x, int v){
  x++;
  ll dif = v - w[x];
  w[x] += dif;
  fw1.add(pos[x],dif);
  fw2.add(pos[x],dif*a[x]);
  return;
}
long long point_fatigue(std::vector<int> B){
  int l = n, r = 1;
  for(auto x : B) {
    x++;
    l = min(l,pos[x]), r = max(r,pos[x]);
  }
  return cal(l,r);
}
long long interval_fatigue(std::vector<std::vector<int>> In){
  int l = n, r = 1;
  for(auto v : In) {
    int a = v[0] + 1, b = v[1] + 1;
    l = min(l, get_mn(a,b)), r = max(r, get_mx(a,b));
  }
  return cal(l, r);
}
