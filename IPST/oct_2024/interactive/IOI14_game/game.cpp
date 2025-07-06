#include "game.h"
#include <bits/stdc++.h>
using namespace std;
const int N = 1503;
int cnt[N];
void initialize(int n) {
}

int hasEdge(int u, int v) {
    return ++cnt[max(u,v)] == max(u,v);
}
