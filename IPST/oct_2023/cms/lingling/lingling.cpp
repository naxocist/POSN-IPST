#include "lingling.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int fw[N], pos[N];

void upd(int i, int x) {
    for(;i<N; i+=i&-i) fw[i] += x;
    return ;
}

int qry(int i) {
    int s = 0;
    for(;i>0;i-=i&-i) s += fw[i];
    return s;
}

void init_monkeys(std::vector<int> P, int Q){
  int N = P.size();
  memset(fw, 0, sizeof fw);
  for(int i=0; i<N; ++i) {
      pos[P[i]+1] = i+1;
      upd(i+1, P[i]-i);
  }
}

long long minimum_branches(int L, int R){
  // edit this function
  L++, R++;
  if(qry(R) - qry(L-1)) return -1;
  return 0;
}