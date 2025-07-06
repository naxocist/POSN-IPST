#include <vector>
#include "penguin.h"

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