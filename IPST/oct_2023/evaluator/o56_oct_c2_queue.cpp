#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
using pi = pair<int, int>;
int fw[N];
unordered_map<int, int> um;

void upd(int i, int x) {
	for(;i<N;i+=i&-i) fw[i] += x;
	return ;
}

int qry(int i) {
	int s = 0;
	for(;i>0;i-=i&-i) s += fw[i];
	return s;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	int q, id=0; cin >> q;
	while(q--) {
		int c; cin >> c;
		if(c == 1) {
			int p; cin >> p;
			upd(p, 1);
			pq.emplace(p, ++id);
			um[id] = p;
		}else if(c == 2) {
			if(!pq.size()) cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				upd(pq.top().first, -1);
				pq.pop();
			}
		}else {
			int x; cin >> x;
			cout << qry(um[x]-1) << '\n';
		}
	}
	return 0;
}