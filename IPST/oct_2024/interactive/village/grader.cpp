#include "village.h"
#include <vector>
#include <cstdio>

int main() {
  int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
  std::vector<int> U(M), V(M), W(M);
  
  for(int i=0; i<M; ++i)   scanf("%d", &U[i]);
  for(int i=0; i<M; ++i) scanf("%d", &V[i]);
  for(int i=0; i<M; ++i) scanf("%d", &W[i]);

  init_village(N, M, Q, U, V, W);
  for (int i = 0; i < Q; i++) {
    int K; scanf("%d", &K);
    std::vector<int> X(K), Y(K);
    for (int i = 0; i < K; i++) scanf("%d %d", &X[i], &Y[i]);
    std::vector<std::vector<int>> ret = move_in(K, X, Y);
    printf("Batch #%d:\n", i);
    for (int j = 0; j < K; j++) {
      printf("Query #%d:\n", j);
      printf("Size is: %d\n", ret[j].size());
      for (auto t : ret[j]) printf("%d ", t);
      printf("\n");
    }
  }
}
