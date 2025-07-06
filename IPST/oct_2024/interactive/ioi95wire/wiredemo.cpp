#include "wirelib.h"
#include <bits/stdc++.h>
using namespace std;

int sol[1000];
int m;

void solve(int l, int r, vector<int> can) {
  if(can.empty()) return ;

  int md = (l+r)/2;
  if(l == r) {
    for(auto x : can) sol[x] = l;
    return ; 
  }


  bool feedback = 0;
  for(int i=md+1; i<=r; ++i) {
    feedback = cmd_C(i) or feedback;
  }

  vector<int> a, b;
  for(int x : can) {
    if(cmd_T(x) == feedback) a.emplace_back(x);
    else b.emplace_back(x);
  }

  solve(l,md,b); solve(md+1,r,a);
}

main()
{
  m = wire_init();
  vector<int> can;
  for(int i=1; i<=m; ++i) can.emplace_back(i);
  solve(1,m,can);

  cmd_D(sol);
}
