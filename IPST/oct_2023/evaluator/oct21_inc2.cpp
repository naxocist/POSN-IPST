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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> lis;
    while(n--) {
        int x; cin >> x;
        auto t = lower_bound(all(lis), x);
        if(t == lis.end()) lis.pb(x);
        else *t = x;
    }
    cout << lis.size();
    return 0;
}
