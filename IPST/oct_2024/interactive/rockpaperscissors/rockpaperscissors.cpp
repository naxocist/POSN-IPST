#include "rockpaperscissors.h"
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

int find_cheater1(int N){ 
  vector<int> t = {0};
  // [1, 3*N]
  int l = 0, r = 3*N+1;
  while(l + 1 < r) {
    int md = l + (r-l)/2;
    vector<int> tmp = t;
    for(int i=l+1; i<=md; ++i) tmp.pb(i);
    if(tournament(tmp) == tmp.size()-1) {
      for(int i=md+1; i<r; ++i) t.pb(i);
      r = md;
    }else {
      for(int i=l+1; i<=md; ++i) t.pb(i);
      l = md;
    }
  }
  return r;
}

int find_cheater2(int N){
  return 0;
}
