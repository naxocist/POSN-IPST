#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

#include "restaurant.h"

ll restaurant(int n, std::vector<int> &v) {
    vector<ll> t(n+1), qs(n+2);
    for(int i=1; i<=n; ++i) t[i] = abs(v[i-1]);
    for(int i=1; i<=n; ++i) qs[i] = qs[i-1] + v[i-1];
    vector<ll> l(n+1), r(n+1);
    stack<pi> mn, mx;
    for(int i=1; i<=n; ++i) {
        l[i] = qs[i-1];
        int d = i-1;
        while(mn.size() and mn.top().second >= t[i]) {
            int k = mn.top().first;
            if(qs[k] < l[i]) l[i] = qs[k], d = k;
            mn.pop();
        }
        mn.emplace(d, t[i]);
    }
    for(int i=n; i>=1; --i) {
        r[i] = qs[i];
        int d = i;
        while(mx.size() and mx.top().second >= t[i]) {
            int k = mx.top().first;
            if(qs[k] > r[i]) r[i] = qs[k], d = k;
            mx.pop();
        }
        mx.emplace(d, t[i]);
    }

    ll res = -LLONG_MAX;
    // for(int i=1; i<=n; ++i) cout << l[i] << ' '; cout << endl;
    // for(int i=1; i<=n; ++i) cout << r[i] << ' '; cout << endl;
    for(int i=1; i<=n; ++i) {
        res = max(res, t[i]*(r[i]-l[i]));
    }
    return res;
}

signed main(int argc, const char **argv) {
    int N;
    assert(scanf("%d", &N));
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        assert(scanf("%d", &A[i]));
    }
    printf("%lld", restaurant(N, A));
    return 0;
}