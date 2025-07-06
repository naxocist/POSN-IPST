#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e4 + 3;
int fw[N][N];

void upd(int x, int y, int v) {
	for(int i=x; i<N; i+=i&-i)
		for(int j=y; j<N; j+=j&-j) 
			fw[i][j] += v;
	return ;
}

int qry(int x, int y) {
	int s = 0;
	for(int i=x; i>0; i-=i&-i)
		for(int j=y; j>0; j-=j&-j) 
			s += fw[i][j];
	return s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
    	int p, h; cin >> p >> h;
    	cout << qry(p-h+5000, N-1) - qry(p-h+5000, p+h-1) <<'\n';
    	upd(p-h+5000, p+h, 1);
    }
    return 0;
}
