#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;

int dp[N], p[10005];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<(1<<m); ++i) dp[i] = 1e7;
    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x);
        p[i] = x;

        int w = 0;
        for(int j=0; j<m; ++j) {
            int b; scanf("%d", &b);
            w |= b;
            w<<=1;
        }
        w>>=1;
        dp[w] = min(dp[w], x);
    }

    for(int i=1; i<(1<<m); ++i) {
        for(int j=i+1; j<(1<<m); ++j) {
            dp[i|j] = min(dp[i|j], dp[i] + dp[j]); // combine tools or not
        }
    }

    printf("%d", dp[(1<<m)-1]);
    return 0;
}