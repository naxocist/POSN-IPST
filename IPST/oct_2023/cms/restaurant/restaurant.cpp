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

#include "restaurant.h"

long long restaurant(int n, std::vector<int> &A) {
        
    ll res = -LLONG_MAX;
    for(int i=0; i<n; ++i) {
        ll a = LLONG_MAX, b = 0;
        for(int j=i; j<n; ++j) {
            b += A[j];
            a = min(a, abs(1LL*A[j]));
            res = max(a * b, res);
        }
    }
    return res;
}
