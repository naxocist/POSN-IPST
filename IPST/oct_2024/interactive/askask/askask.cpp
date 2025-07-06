#include "askask.h"
#include <bits/stdc++.h>
using namespace std;

std::vector<int> find_bombs(int N){
  int n = N;

  if(n != 64) {
    vector<vector<int>> a;

    for(int i=0; 1<<i<n; ++i) {
      vector<int> t;
      for(int j=0; j<n; ++j) if(j&(1<<i)) t.emplace_back(j); 
      a.push_back(t);
    }

    vector<bool> x = analyse(a);
    int res = 0;
    for(int i=0; 1<<i<n; ++i) res |= x[i]<<i;

    return {res, res};
  }

  vector<vector<int>> a;
  for(int i=0; i<8; ++i) {
    vector<int> t;
    for(int j=0; j<8; ++j) t.emplace_back((i<<3)|j);
    a.emplace_back(t);
  }


  for(int i=0; i<8; ++i) {
    vector<int> t;
    for(int j=0; j<8; ++j) t.emplace_back((j<<3)|i);
    a.emplace_back(t);
  }

  for(int i=0; i<8; ++i) {
    vector<int> t;
    for(int k=0; k<64; ++k) {
      if(((k/8)^(k%8)) == i) t.emplace_back(k);
    }
    a.emplace_back(t);
  }

  vector<bool> x = analyse(a);
  vector<int> res;
  for(int i=0; i<8; ++i) {
    for(int j=0; j<8; ++j) {
      if(!x[i] or !x[8+j] or !x[16+(i^j)]) continue ;
      res.emplace_back((i<<3)|j);
    }
  }

  if(res.size() == 1) res.emplace_back(res.back());
  return res;
}
