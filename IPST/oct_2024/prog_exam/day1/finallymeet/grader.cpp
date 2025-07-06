#include "finallymeet.h"
#include <cstdio>
#include <vector>

int N,M;
std::vector<int> U,V;

void read_input()
{
  int dummy;
  dummy = scanf("%d %d",&N,&M);
  U.resize(M);
  V.resize(M);

  for(int i=0; i<M; ++i) scanf("%d", &U[i]);
  for(int i=0; i<M; ++i) scanf("%d", &V[i]);
}

int main()
{
  read_input();
  long long res = count_init(N,M,U,V);
  printf("%lld\n",res);
}
