#include "spectrophotometer.h"

#define ln '\n'
#include "bits/stdc++.h"
using namespace std;

void sort_lasers(int N) {
  // 0:N-1 | N:2N-1 | 2N:3N-1

  vector<int> mark = {2*N-1};
  for(int i=0; i<2*N-1; ++i) {
    if(call_swap(i, i+1)) {
      mark.emplace_back(i);
    }
  }

  int to = 2*N;
  while(mark.size()) {
    if(!call_swap(mark.back(), to)) {
      mark.pop_back();
    }
    to++;
  }


  mark.clear();
  mark.push_back(N-1);
  for(int i=0; i<N-1; ++i) {
    if(call_swap(i, i+1)) {
      mark.emplace_back(i);
    }
  }

  to = N;
  while(mark.size()) {
    if(!call_swap(mark.back(), to)) {
      mark.pop_back();
    }
    to++;
  }
  return ;
}
