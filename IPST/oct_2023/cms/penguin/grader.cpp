#include "penguin.h"
#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

const int MAX_CALL = 250;

int N, POS;
int CALL_COUNT = 0;
int K = 0;
bool FOUND = false;


void penguin(int N) {
    if(N == 2) {
        play({1});
        play({1});
        return ;
    }
    
    for(int i=2; i<N; i++) {
        if(play({i})) return ;
    }

    if(N&1^1) {
        for(int i=N-1; i>=2; i--) {
            if(play({i})) return ;
        }
    }

    for(int i=2; i<N; ++i) {
        if(play({i})) break ;
    }
    // cout << i << '\n';
    return;
}


bool play(std::vector<int> A) {
    assert(++CALL_COUNT <= MAX_CALL);
    printf("move #%d : ", CALL_COUNT);
    int D;
    assert(scanf("%d", &D) == 1);
    if(D == 1){
        POS++;
    }else{
        POS--;
    }
    assert(1 <= POS && POS <= N);
    int k = (int)A.size();
    assert(1 <= k && k <= N);
    K += k * k * k;
    for(int i = 0; i < k; i++) {
        if(A[i] == POS) {
            return FOUND = true;
        }
    }
    return false;
}

signed main(int argc, const char **argv) {
    assert(scanf("%d%d", &N, &POS) == 2);
    penguin(N);
    if(FOUND) {
        printf("Correct.\n");
        printf("Total Cost : %d\n", K);
    }else{
        printf("Incorrect.\n");
    }
    return 0;
}