#include <cassert>
#include <cstdio>
#include <vector>
#include "card.h"

void wrong_answer(int code) {
    printf("Wrong Answer [%d]\n", code);
    exit(0);
}

int main(int argc, char **argv) {
    int N, Q;
    assert(scanf("%d %d", &N, &Q) == 2);
    std::vector<std::vector<int>> B(Q);
    std::vector<int> answer(Q);
    for(int i = 0; i < Q; i++) {
        std::vector<int> A(6);
        for(int j = 0; j < 6; j++) {
            assert(scanf("%d", &A[j]));
            assert(0 <= A[j] && A[j] <= N - 1);
        }
        B[i] = Shin(N, A);
        if((int) B[i].size() != 5) {
            wrong_answer(1);
        }
        for(int j = 0; j < 5; j++) {
            bool found = false;
            for(int k = 0; k < 6; k++) {
                if(B[i][j] == A[k]) {
                    A[k] = -1;
                    found = true;
                    break;
                }
            }
            if(!found) {
                wrong_answer(2);
            }
        }
        for(int j = 0; j < 6; j++) {
            if(A[j] != -1) {
                answer[i] = A[j];
                break;
            }
        }
    }
    for(int i = 0; i < Q; i++) {
        int output = Lena(N, B[i]);
        if(output != answer[i]) {
            wrong_answer(3);
        }
    }
    printf("Accepted.\n");
}
