#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

void solve() {

    int R, C, n, T, r, c; scanf("%d%d%d%d%d%d", &R, &C, &n, &T, &r, &c);

    vector<vector<int>> ar(R, vector<int>(C, 1e9));
    vector<vector<int>> pac(R, vector<int>(C, 1e9));

    queue<pi> q;
    int x, y, t; 
    while(n--) {
        scanf("%d%d%d", &t, &x, &y);
        q.emplace(x, y);
        ar[x][y] = t;
    }

    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            char k; scanf(" %c", &k);
            if(k == '#') ar[i][j] = -1;
        }
    }

    int mv[] = {1, 0, -1, 0, 1};

    while(q.size()) {
        tie(x, y) = q.front(); q.pop();

        for(int i=0; i<4; ++i) {
            int h = x + mv[i], k = y + mv[i+1];
            if(h < 0 || k < 0 || h >= R || k >= C || ar[x][y] + 1 >= ar[h][k]) continue ;
            ar[h][k] = ar[x][y] + 1;
            q.emplace(h, k);
        }
    }
    
    q.emplace(r, c);
    pac[r][c] = 0;
    while(q.size()) {
        tie(x, y) = q.front(); q.pop();

        for(int i=0; i<4; ++i) {
            int h = x + mv[i], k = y + mv[i+1];
            if(h < 0 || k < 0 || h >= R || k >= C || pac[h][k] != 1e9 || ar[h][k] == -1 || pac[x][y] + 1 >= ar[h][k]) continue ;
            pac[h][k] = pac[x][y] + 1;
            q.emplace(h, k);

        }
    }

    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            if(pac[i][j] <= T && ar[i][j] > T) {
                printf("YES\n");
                return ;
            }
        }
    }
    
    printf("NO\n");
    return ;
}

int main() {

    int t; scanf("%d", &t);
    while(t--) solve();
    return 0;
}
