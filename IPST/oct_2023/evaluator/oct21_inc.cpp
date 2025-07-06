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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    
    vector<int> rev(n, -1), dp(n, 1);
    int mx = 1, idx = 0;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(v[j] < v[i] and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                rev[i] = j;
            }
        }
        if(dp[i] > mx) mx = dp[i], idx = i;
    }
    cout << dp[idx] << '\n';
    stack<int> st;
    while(idx != -1) {
        st.push(idx);
        idx = rev[idx];
    }
    while(st.size()) cout << v[st.top()] << ' ', st.pop();
    return 0;
}
