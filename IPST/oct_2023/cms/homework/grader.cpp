#include "homework.h"
#include <bits/stdc++.h>
#include "homework.cpp"
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<ll, ll, ll>;

int main() {
    int N;
    scanf("%d",&N);
    std::vector<std::vector<int>> HW(N,std::vector<int>(4));
    std::vector<std::vector<int>> B(N);
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < 4;j++) {
            scanf("%d",&HW[i][j]);
        }
    }
    for(int i = 0;i < N;i++) {
        int c;
        scanf("%d",&c);
        B[i].resize(c);
        for(int j = 0;j < c;j++) {
            scanf("%d",&B[i][j]);
        }
    }
    printf("%d",homework(N,HW,B));
}