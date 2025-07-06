#include "card.h"
#include <bits/stdc++.h>
using namespace std;

namespace SHIN{
  int variable_example = 0;
}

namespace LENA{
  int variable_example = 0;
}

int d(int a, int b, int n) {
  int sz = (n+4)/5;
  if(a > b) swap(a, b);
  //cout << a << ' ' << b << endl;
  if(sz == 1) return b - a;
  return min(b-a, sz-b+a);
}

std::vector<int> Shin(int N, std::vector<int> A) {
  vector<int> t;
  sort(A.begin(), A.end());

  int sz = (N+4)/5;
  vector<int> group[5];
  
  bool has[245];
  for(int k=sz, i=0; i<5; k+=sz, i++) {
    for(int x : A) {
      if(k-sz <= x and x < k) group[i].emplace_back(x), has[x] = 1;
    }
  }

  for(auto a : A){ 
    if(!has[a]) group[4].emplace_back(a);
  }

  int out, keep;
  for(int i=0; i<5; ++i) {
    //cout << i << ": ";
    //for(auto g : group[i]) cout << g << ' '; cout << endl;
    if(group[i].size() > 1) {
      // out > keep
      out = group[i].back(); group[i].pop_back();
      keep = group[i].back();
      break ;
    }
  }


  if(sz > 1 and out - keep > sz/2) swap(out, keep); 
  //cout << out << ' ' << keep << endl;

  vector<int> vec;
  for(auto x : A) {
    if(x == out or x == keep) continue ;
    vec.emplace_back(x);
  }

  int send = d(out, keep, N); send--;
 //cout << "send : " << send << endl;
  while(send-- and next_permutation(vec.begin(), vec.end())) {}

  vec.emplace_back(keep);
  //for(auto v : vec) cout << v << ' '; cout << endl;
  return vec;
}

int Lena(int N, std::vector<int> B) {
  LENA::variable_example++;

  int keep = B.back();
  B.pop_back();

  vector<int> t(B);
  sort(t.begin(), t.end());

  //for(auto b : B) cout << b << ' ' ;cout << endl;
  int receive = 0;
  do {
    if(t == B) break ;
    receive ++;
  }while(next_permutation(t.begin(), t.end()));
  receive ++;

  int sz = (N+4)/5;
  int base = 0;
  //int base = keep/sz * sz;
  for(int i=0; i<5; ++i) {
    if(base + sz > keep) break; 
    base += sz; 
  }

  //cout << base << ' ' << sz << endl;
  int res = (keep + receive - base)%sz + base;
  //cout << "K: " ;
  //cout << keep << ' ' << receive << endl;
  //cout << "RES: " << res << endl;
  return res;
}
