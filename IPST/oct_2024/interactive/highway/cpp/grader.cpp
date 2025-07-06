#include <cassert>
#include <cstdio>
#include <vector>
#include "highway.h"

int main(int argc, char **argv) {
    int N, Q;
    assert(scanf("%d %d", &N, &Q) == 2);
    std::vector<int> A(N - 1), B(N - 1), C(N);
    for(int i = 0; i < N - 1; i++) {
        assert(scanf("%d", &A[i]) == 1);
    }
    for(int i = 0; i < N - 1; i++) {
        assert(scanf("%d", &B[i]) == 1);
    }
    for(int i = 0; i < N; i++) {
        assert(scanf("%d", &C[i]) == 1);
    }
    init(N, Q, A, B, C);
    for(int i = 0; i < Q; i++) {
        int OP;
        assert(scanf("%d", &OP) == 1);
        if(OP == 1) {
            int X, Y, Z;
            assert(scanf("%d %d %d", &X, &Y, &Z) == 3);
            update(X, Y, Z);
        } else if(OP == 2) {
            int S, T;
            assert(scanf("%d %d", &S, &T) == 2);
            printf("%lld\n", query(S, T));
        } else {
            assert(false);
        }
    }
}
