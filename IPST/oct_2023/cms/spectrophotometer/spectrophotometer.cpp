#include "spectrophotometer.h"
#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

void sort_lasers(int N) {
  if(N == 1) return ;

  int n = 3*N;
  int l = N, r = 2*N;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;

  vector<bool> v(n);
  for(int i=0; i<n-1; ++i) {
    v[i] = call_swap(i, i+1);
  }

  v[n-1] = 1;
  for(int i=0; i<l; ++i) cnt1 += v[i];
  for(int i=l; i<r; ++i) cnt2 += v[i];
  for(int i=r; i<n; ++i) cnt3 += v[i];

  int mx = max({cnt1, cnt2, cnt3});
  // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
  stack<int> a;
  if(mx == cnt1) 
  {
    for(int i=l; i<n; ++i) if(v[i]) a.push(i);
    
    for(int i=0; i<l; ++i) {
      if(!v[i]) call_swap(i, a.top()), a.pop();
    }

    int a = l, b = l+1;
    while(a < n and b < n) {
      if(call_swap(a, b)) b++;
      else a ++, b ++;
    }
     
  }
  else if(mx == cnt2) 
  { 
    for(int i=0; i<l; ++i) if(v[i]) a.push(i);
    for(int i=r; i<n; ++i) if(v[i]) a.push(i);
    
    for(int i=l; i<r; ++i) {
      if(!v[i]) call_swap(i, a.top()), a.pop();
    }

    int a = 0, b = 1;
    while(a < n and b < n) {
      if(call_swap(a, b)) b ++;
      else a ++, b ++;
      if(b == l) b = r;
      if(a == l) a = r;
    }
  }  
  else 
  {
    for(int i=0; i<r; ++i) if(v[i]) a.push(i);
    for(int i=r; i<l; ++i) {
      if(!v[i]) call_swap(i, a.top()), a.pop();
    }

    int a = 0, b = 1;
    while(a < n and b < n) {
      if(call_swap(a, b)) b ++;
      else a ++, b ++;
    }
  }  
}